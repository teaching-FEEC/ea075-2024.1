/*!
 * @file ISR.h
 * @brief Este modulo contem declaracoes relacionadas com o modulo ISR.c
 * @author Wu Shin Ting
 * @date 06/03/2022
 */

#ifndef ISR_H_
#define ISR_H_

#include <stdint.h>

#include "util.h"

typedef enum {
    AMOSTRA_TEMP,
    AMOSTRA_VOLT,
    ATUALIZACAO
} state_t;

/**
 * @brief Le estado do sistema
 * @return estado do sistema
 */
state_t ISR_LeEstado();

/**
 * @brief Muda o estado do programa
 *
 * @param[in] s novo estado
 */
void ISR_setState(state_t s);

/**
 * @brief Le 2 valores amostrados
 * @param[out] amostras 2 amostras
 */
void ISR_LeValoresAmostrados(uint8_t *amostras);

#endif /* ISR_H_ */
