/*!
 * @file ISR.c
 * @brief Este modulo contem as rotinas de servico do aplicativo
 * @author Wu Shin Ting
 * @date 06/03/2022
 */
#include "derivative.h"
#include "ISR.h"
#include "ADC.h"

/*!
 * Declarar variaveis GLOBAIS de controle
 */
static uint8_t valor[2];		///< valor convertido do sensor LM61
static uint8_t estado;

/**
 * @brief Rotina de servico do IRQ 15 (ADC0)
 */
void ADC0_IRQHandler(void) {
	static uint8_t result;
	if( ADC0_SC1A & ADC_SC1_COCO_MASK )
	{
		result = (uint8_t)ADC0_RA;					//!< \li \l guardar o valor amostrado
		if (estado == AMOSTRA_VOLT) {
			valor[0] = result;
			ADC0_SC2 &= ~ADC_SC2_ADTRG_MASK;	//!< \li \l chavear para trigger por software
			ADC_selecionaCanal (0b11010); 			//!< \li \l selecionar o canal do sensor AN3031
			estado = AMOSTRA_TEMP;
		} else if (estado == AMOSTRA_TEMP) {
			valor[1] = result;
			ADC0_SC2 |= ADC_SC2_ADTRG_MASK;		//!< \li \l chavear para trigger por hardware
			ADC_selecionaCanal (0b01001); 			//!< \li \l selecionar o canal do header H7
			estado = ATUALIZACAO;
		}
	}
}


uint8_t ISR_LeEstado() {
	return estado;
}

void ISR_setState(state_t s) {
    estado = s;
}

void ISR_LeValoresAmostrados (uint8_t *v) {
	v[0] = valor[0];
	v[1] = valor[1];
	
	return;
}

