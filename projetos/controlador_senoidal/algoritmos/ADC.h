/*
 * @file ADC.h
 * @brief Prototipos, macros e tipos de dados para funcoes de ADC
 * @date Feb 4, 2023
 * @author Wu Shin-Ting
 */

#include "derivative.h"

#ifndef ADC_H_
#define ADC_H_

#define PIT0_TRG      0b0100
#define PIT1_TRG	  0b0101
#define TPM1_TRG      0b1001
#define LPTMR0_TRG 	  0b1110

#define ADLPC_NORMAL 0
#define ADLPC_LP ADC_CFG1_ADLPC_MASK

#define ADIV_1 0b00
#define ADIV_2 0b01
#define ADIV_4 0b10
#define ADIV_8 0b11

#define ADLSMP_SHORT 0
#define ADLSMP_LONG ADC_CFG1_ADLSMP_MASK

#define MODE_8 0b00
#define MODE_12 0b01
#define MODE_10 0b10
#define MODE_16 0b11

#define ADICLK_BUS 0b00
#define ADICLK_BUS_2 0b01
#define ADICLK_ALTCLK 0b10
#define ADICLK_ADACK 0b11

#define MUXSEL_ADCA 0
#define MUXSEL_ADCB ADC_CFG2_MUXSEL_MASK

#define ADACKEN_DISABLED 0
#define ADACKEN_ENABLED ADC_CFG2_ADACKEN_MASK

#define ADHSC_NORMAL 0
#define ADHSC_HISPEED ADC_CFG2_ADHSC_MASK

#define ADLSTS_20 0b00
#define ADLSTS_12 0b01
#define ADLSTS_10 0b10
#define ADLSTS_2 0b11

#define ADTRG_SW 0
#define ADTRG_HW ADC_SC2_ADTRG_MASK

#define ACFE_DISABLED 0
#define ACFE_ENABLED ADC_SC2_ACFE_MASK

#define ACFGT_LESS 0
#define ACFGT_GREATER ADC_SC2_ACFGT_MASK

#define ACREN_DISABLED 0
#define ACREN_ENABLED ADC_SC2_ACREN_MASK

#define DMAEN_DISABLED 0
#define DMAEN_ENABLED ADC_SC2_DMAEN_MASK

#define REFSEL_EXT 0b00
#define REFSEL_ALT 0b01

#define CAL_OFF 0
#define CAL_ON ADC_SC2_ADACT_MASK

#define ADCO_SINGLE 0
#define ADCO_CONTINUOUS ADC_SC3_ADCO_MASK

#define AVGE_DISABLED 0
#define AVGE_ENABLED ADC_SC3_AVGE_MASK

#define AVGS_4 0b00
#define AVGS_8 0b01
#define AVGS_16 0b10
#define AVGS_32 0b11

#define AIEN_OFF 0
#define AIEN_ON	ADC_SC1_AIEN_MASK

#define DIFF_SINGLE	0
#define DIFF_DIFFERENTIAL ADC_SC1_DIFF_MASK

#define ADC0A_DONE 1

/**
 * @brief Habilita sinais de relogio e aloca o pino para o canal SE9/PTB1 de ADC
 * @param[in] trigger fontte de disparo por HW
 */
void ADC_PTB1_config_basica(uint8_t trigger);

/**
 * @brief Copia um bloco de dados para um espaco de memoria
 * @param[in] end endereco de memoria para onde eh feito a copia
 * @param[in] dados bloco de dados a ser copiado
 */
void ADC_Config_Alt (ADC_MemMapPtr end, ADC_MemMapPtr dados);

/**
 * @brief Calibrar ADC mapeado no endereco de memoria especificado contendo os dados 
 * de configuracao.
 * @param[in] end endereco de memoria em que ADC eh mapeado.
 */
void ADC_Cal (ADC_MemMapPtr end);

/**
 * @brief Habilita IRQ 15 (ADC0) no NVIC
 * @param[in] prioridade de atendimento
 */
void ADC_habilitaNVICIRQ(uint8_t prioridade);

/**
 * @brief Seleciona o canal a ser amostrado
 * @param[in] canal selecionado
 */
void ADC_selecionaCanal(uint8_t canal);

/**
 * @brief Habilita Interrupcao COCO
 */
void ADC_habilitaInterrupCOCO();

#endif /* ADC_H_ */
