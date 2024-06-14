* @file main.c
 * @brief Este projeto demonstra o uso de ADC cuja amostragem eh iniciada por disparos por hardware (PIT)
 * @author Wu Shin Ting
 * @date 23/10/2021
 *
 */

#include "ADC.h"
#include "GPIO_latch_lcd.h"
#include "ISR.h"
#include "SIM.h"
#include "TPM.h"
#include "util.h"

#define MAX 0xff  ///< resolucao 8 bits
#define TPM1_MOD_VALUE 0xfff
#define VDD 3.3
#define V25 0.703125

// Configuracao do ADC0
struct ADC_MemMap Master_Adc_Config = {
    .SC1[0] = AIEN_OFF | DIFF_SINGLE | ADC_SC1_ADCH(31),
    .SC1[1] = AIEN_OFF | DIFF_SINGLE | ADC_SC1_ADCH(31),
    .CFG1 = ADLPC_NORMAL | ADC_CFG1_ADIV(ADIV_4)
            //		 | ADC_CFG1_ADIV(ADIV_8)
            | ADLSMP_LONG
            //		 | ADLSMP_SHORT
            | ADC_CFG1_MODE(MODE_8)
            //		 | ADC_CFG1_MODE(MODE_16)
            | ADC_CFG1_ADICLK(ADICLK_BUS_2),
    .CFG2 = MUXSEL_ADCA  // select ADC0_SE9 (PTB1 potenciometro externo)
            | ADACKEN_DISABLED | ADHSC_HISPEED
            //		 | ADHSC_NORMAL,
            | ADC_CFG2_ADLSTS(ADLSTS_20),
    .CV1 = 0x1234u,
    .CV2 = 0x5678u,
    .SC2 = ADTRG_HW  // Hardware trigger
           | ACFE_DISABLED | ACFGT_LESS | ACREN_DISABLED | DMAEN_DISABLED | ADC_SC2_REFSEL(REFSEL_EXT),
    .SC3 = CAL_OFF | ADCO_SINGLE | AVGE_ENABLED | ADC_SC3_AVGS(AVGS_8),
    //		 | ADC_SC3_AVGS(AVGS_16),
};

struct ADC_MemMap Op_Adc_Config = {
    .SC1[0] = AIEN_OFF | DIFF_SINGLE | ADC_SC1_ADCH(31),
    .SC1[1] = AIEN_OFF | DIFF_SINGLE | ADC_SC1_ADCH(31),
    .CFG1 = ADLPC_NORMAL | ADC_CFG1_ADIV(ADIV_4) | ADLSMP_SHORT | ADC_CFG1_MODE(MODE_12) | ADC_CFG1_ADICLK(ADICLK_BUS),
    .CFG2 = MUXSEL_ADCA  // select ADC0_SE9 (PTB1 potenciometro externo)
            | ADACKEN_DISABLED | ADHSC_NORMAL | ADC_CFG2_ADLSTS(ADLSTS_20),
    .CV1 = 0x1234u,
    .CV2 = 0x5678u,
    .SC2 = ADTRG_HW  // Hardware trigger
           | ACFE_DISABLED | ACFGT_LESS | ACREN_DISABLED | DMAEN_DISABLED | ADC_SC2_REFSEL(REFSEL_EXT),
    .SC3 = CAL_OFF | ADCO_SINGLE | AVGE_ENABLED | ADC_SC3_AVGS(AVGS_8),
};

int main(void) {
    char string[32];
    uint8_t amostras[2] = {0, 0};
    float duty = 0.0, temp = 0.0, Vtemp = 0.0;

    /*
     * Seta o divisor de frequencia do sinal do barramento
     */
    SIM_setaOUTDIV4(0b001);
    //	SIM_setaOUTDIV4 (0b000);

    /*
     * Configura os pinos do Latch 74751
     */
    //	GPIO_ativaConLatchLCD();
    GPIO_ativaConLCD();
    GPIO_initLCD();

    /*
     * Configura o modulo ADC
     */
    // Ativa sinais de relogio e multiplexa pino para canal 9 (SE9) com disparo HW (PIT0)
    ADC_PTB1_config_basica(TPM1_TRG);

    // Configuracao especifica e calibracao do modulo ADC
    ADC_Config_Alt(ADC0_BASE_PTR, &Master_Adc_Config);  //!!! configura via "drive ADC"
    ADC_Cal(ADC0_BASE_PTR);                             //!!! calibra (Secao 28.4.6/p.494 no Manual)
    ADC_Config_Alt(ADC0_BASE_PTR, &Master_Adc_Config);  // reconfigura

    /*
     * Configura fonte de pulsos para contadores de TPMs (MCGFLLCLK)
     */
    SIM_setaTPMSRC(0b01);

    /*
     * Configurar MCGFLLCLK 20971520Hz com fonte de sinais de relogio
     */
    SIM_setaFLLPLL(0);

    TPM1_PTB0_config_basica();

    TPM_config_especifica(1, TPM1_MOD_VALUE, 0b1111, 0, 0, 0, 0, 0, 0b111);  // (4095*128)/20971520 = 0.02s
    TPM_CH_config_especifica(1, 0, 0b1010, 0);

    // Habilita interrupcoes no NVIC
    ADC_habilitaNVICIRQ(2);

    GPIO_escreveByteLatch(0x00);  // apagar os leds vermelhos
    ADC_selecionaCanal(0b01001);  // selecionar o canal do header H7 (PTB1/SE9)

    // Habilita interrupcao do ADC
    ADC_habilitaInterrupCOCO();

    GPIO_escreveStringLCD(0x00, (uint8_t *)"                ");
    GPIO_escreveStringLCD(0x40, (uint8_t *)"                ");
    string[1] = '\0';
    ISR_setState(AMOSTRA_VOLT);

    /*!
     * Laco de interacoes
     */
    for (;;) {
        /*!
         * Polling pela mudanca de estados e valores.
         * Eles podem estar defasados, mas sao os valores mais
         * recentes amostrados.
         */
        ISR_LeValoresAmostrados(amostras);

        // visualiza os dois valores amostrados dos sensores
        if (ISR_LeEstado() == ATUALIZACAO) {
            TPM_setaCnV(1, 0, 1. * amostras[0] / MAX * TPM1_MOD_VALUE);
            duty = 100. * amostras[0] / 255;
            ftoa(duty, string, 1);
            GPIO_escreveStringLCD(0x00, (uint8_t *)string);
            Vtemp = 1. * amostras[1] / MAX * VDD;
            temp = 25 - (Vtemp - V25) / (Vtemp >= V25 ? 1.646 : 1.769);
            ftoa(temp, string, 1);
            GPIO_escreveStringLCD(0x40, (uint8_t *)string);
            GPIO_escreveByteLatch(amostras[1]);
            ISR_setState(AMOSTRA_VOLT);
        }
    }
    return 1;
}
