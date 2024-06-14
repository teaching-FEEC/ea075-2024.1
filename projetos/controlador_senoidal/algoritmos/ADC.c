/*
 * @file ADC.c
 * @brief Funcoes relacionadas com o modulo ADC
 * @data Feb 4, 2023
 * @author Wu Shin-Ting
 * 
 * @note https://www.nxp.com/docs/en/supporting-information/Analog-to-digital-Converter-Training.pdf
 */

#include "derivative.h"
#include "ADC.h"

void ADC_PTB1_config_basica(uint8_t trigger) {
	
	/*
	 * Habilita os sinais de relógio para ADC0
	 */
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;

	/*
	 * Habilita LPTMR como trigger
	 */
//	SIM_SOPT7 |= (SIM_SOPT7_ADC0ALTTRGEN_MASK
//	 | !SIM_SOPT7_ADC0PRETRGSEL_MASK
//	 | SIM_SOPT7_ADC0TRGSEL(trigger)) ;
	SIM_SOPT7 &= ~SIM_SOPT7_ADC0PRETRGSEL_MASK;
	
	SIM_SOPT7 |= (SIM_SOPT7_ADC0ALTTRGEN_MASK
	 | SIM_SOPT7_ADC0TRGSEL(trigger)) ;

	/*
	 * Configura pinos PTB1 e PTB18
	 */ 
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;				//habilita sinais de relogio

	PORTB_PCR1 &= ~PORT_PCR_MUX(0b111);		// na inicializacao o valor eh 0b000
	
	return;
}

void ADC_Config_Alt (ADC_MemMapPtr end, ADC_MemMapPtr dados) {
	end->SC1[0] = dados->SC1[0];
	end->SC1[1] = dados->SC1[1];
	end->CFG1 = dados->CFG1;
	end->CFG2 = dados->CFG2;
	end->CV1 = dados->CV1;
	end->CV2 = dados->CV2;
	end->SC2 = dados->SC2;
	end->SC3 = dados->SC3;
	
	return;
}

void ADC_Cal (ADC_MemMapPtr end) {
	uint16_t tmp=0;

	/*
	 * Configurar frequencia ADCK (<= 4MHz) e resolucao, formato de saida
	 * fonte do sinal de relogio MCGFLLCLK 20.971.520Hz
	 */ 
	end->CFG1 &= ~ADC_CFG1_ADICLK_MASK;
	end->CFG1 |= ADC_CFG1_ADIV(ADIV_8);

	/*!
	 * Trigger deve ser por software
	 */
	end->SC2 &= ~ADC_SC2_ADTRG_MASK;
	
	/**
	 * Configurar modo de amostrage e media das amostras (32)
	 */ 
	end->SC3 &= ~(ADC_SC3_AVGE_MASK |
			ADC_SC3_AVGS_MASK);

	end->SC3 |= ADC_SC3_AVGE_MASK |
			ADC_SC3_AVGS(AVGS_32);

	/*!
	 * Calibrar
	 */
	end->SC3 |= (ADC_SC3_CAL_MASK);			///< inicializa a calibracao	
	while (end->SC3 & ADC_SC3_CAL_MASK)  {}	///< aguarda a calibracao

	/*!
	 * Gerar as correcos de erros de ganho (positivo)
	 */ 
	tmp = end->CLP0 + end->CLP1 + end->CLP2 + 
			end->CLP3 + end->CLP4 + end->CLPS;	///< soma PS
	tmp = tmp/2;								///< divide por 2
	tmp |= (uint16_t)(0x8000);					///< setar o bit mais significativo
	end->PG = tmp;								///< plus-side gain

	/*!
	 *  Somente util para modos diferenciais 
	 */
	tmp = end->CLM0 + end->CLM1 + end->CLM2 + 
			end->CLM3 + end->CLM4 + end->CLMS;	///< soma PS
	tmp = tmp/2;								///< divide por 2
	tmp |= (uint16_t)(0x8000);					///< setar o bit mais significativo
	end->MG = tmp;								///< minus side gain

	/*!
	 * A compensacao do erro de offset eh atribuida em ADC0_OFS automaticamente
	 */ 	
}

void ADC_habilitaNVICIRQ(uint8_t prioridade) {
	
	/**
	 * Configura o modulo NVIC: habilita IRQ irq
	 */
	NVIC_ISER = NVIC_ISER_SETENA(1<<15);	

	/**
	 * Configura o modulo NVIC: limpa pendencias IRQ irq==15
	 */
	NVIC_ICPR = NVIC_ICPR_CLRPEND(1<<15);	

	/**
	 * Configura o modulo NVIC: seta prioriodade 3 para IRQ
	 * registrador NVIC_IPRn n = irq/4(Tabela 3-7/p. 53 do Manual)
	 * campo dentro do registrador: (irq%4)*8
	 */
	NVIC_IP_REG(NVIC_BASE_PTR,15/4) |= (prioridade<<6) << (15%4*8); //(Secao 3.3.2.1/p. 53 do Manual)
	
	return;

}

void ADC_selecionaCanal(uint8_t canal) {
	ADC0_SC1A &= ~ADC_SC1_ADCH(0b11111);
	ADC0_SC1A |= ADC_SC1_ADCH(canal);
}

void ADC_habilitaInterrupCOCO() {
	ADC0_SC1A |= ADC_SC1_AIEN_MASK;
}
