/**
 * @file util.h
 * @brief Prototipos, macros e tipos de dados de util.c
 * @date 05/04/2024
 * @author Wu Shin-Ting
 * @author Gustavo Nascimento Soares
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <stdint.h>

#define GPIO_PIN(x) ((1) << (x))

/**
 * @brief Executa em multiplos de 2us sem outras alteracoes
 *
 * Tempo final de execucao sera n * 2us
 *
 * @param[in] n multiplica 2us
 */
void espera_2us(uint32_t n);

/**
 * @brief Converte um valor em ponto flutuante, sem sinal, para uma string com a
 * qte de digitos decimais especificada
 * @param[in] n valor inteiro
 * @param[out] res string
 * @param[in] afterpoint qtde dde digitos decimais
 */
void ftoa(float n, char* res, uint8_t afterpoint);

#endif /* UTIL_H_ */
