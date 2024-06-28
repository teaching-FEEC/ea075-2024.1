/*
 * @name SIM.c
 * @brief Definicao de funcoes de derivacao de sinais de relogio
 * @date Jan 16, 2023
 * @author Wu Shin-Ting
 */
#include "derivative.h"

void SIM_setaOUTDIV4 (uint8_t OUTDIV4) {
	/*
	 * Configurar a frequencia do clock de barramento atraves do divisor da frequencia 
	 * do sinal MCGOUTCLK  (clock de barramento = MCGOUTCLK/(OUTDIV1*OUTDIV4))
	 */
	SIM_CLKDIV1 &= ~SIM_CLKDIV1_OUTDIV4(0b111); // setar OUTDIV4
	SIM_CLKDIV1 |= SIM_CLKDIV1_OUTDIV4(OUTDIV4); 	
}

void SIM_setaFLLPLL (uint8_t pll) {
	/*
	 * Selecionar o modo de geracao por laco de sincronismo
	 */
	if (pll) {
		SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK; // setar PLL
	} else {
		SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK; // setar FLL
	}
}

void SIM_reseta() {
	SIM_SOPT1 &= ~(SIM_SOPT1_USBREGEN_MASK |
			SIM_SOPT1_USBSSTBY_MASK |
			SIM_SOPT1_USBVSTBY_MASK |
			SIM_SOPT1_OSC32KSEL(0b11));
	SIM_SOPT1CFG &= ~(SIM_SOPT1CFG_USSWE_MASK |
			SIM_SOPT1CFG_UVSWE_MASK |
			SIM_SOPT1CFG_URWE_MASK);
	SIM_SOPT4 &= ~(SIM_SOPT4_TPM2CLKSEL_MASK |
			SIM_SOPT4_TPM1CLKSEL_MASK |
			SIM_SOPT4_TPM0CLKSEL_MASK |
			SIM_SOPT4_TPM2CH0SRC_MASK |
			SIM_SOPT4_TPM1CH0SRC_MASK);
	SIM_SOPT5 &= ~(SIM_SOPT5_UART2ODE_MASK |
			SIM_SOPT5_UART1ODE_MASK |
			SIM_SOPT5_UART0ODE_MASK |
			SIM_SOPT5_UART1RXSRC_MASK |
			SIM_SOPT5_UART1TXSRC_MASK |
			SIM_SOPT5_UART0RXSRC_MASK |
			SIM_SOPT5_UART0TXSRC_MASK );
	SIM_SOPT7 &= ~(SIM_SOPT7_ADC0ALTTRGEN_MASK |
			SIM_SOPT7_ADC0PRETRGSEL_MASK |
			SIM_SOPT7_ADC0TRGSEL(0b1111));
	SIM_SCGC4 &= (SIM_SCGC4_SPI1_MASK |
			SIM_SCGC4_SPI1_MASK |
			SIM_SCGC4_SPI0_MASK |
			SIM_SCGC4_CMP_MASK |
			SIM_SCGC4_USBOTG_MASK |
			SIM_SCGC4_UART2_MASK |
			SIM_SCGC4_UART1_MASK |
			SIM_SCGC4_UART0_MASK |
			SIM_SCGC4_I2C1_MASK |
			SIM_SCGC4_I2C0_MASK);
	
	return;
}

void SIM_setaTPMSRC (uint8_t src) {
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(src) ;
}
