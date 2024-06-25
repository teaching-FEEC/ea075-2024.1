#ifndef TPM_H_
#define TPM_H_

#include <stdint.h>

void TPM1_PTB0_config_basica();
void TPM_config_especifica(uint8_t x, uint16_t mod, uint8_t trigger, uint8_t crot, uint8_t csoo, uint8_t csot,
                           uint8_t dma, uint8_t cpwms, uint8_t ps);
void TPM_CH_config_especifica(uint8_t x, uint8_t n, uint8_t MS_ELS, uint16_t valor);
void TPM_setaCnV(uint8_t x, uint8_t n, uint16_t valor);

#endif
