/**
 * @file util.c
 * @brief Definicao das funcoes uteis do projeto
 * @date 04/05/2024
 * @author Wu Shin Ting
 * @author Gustavo Nascimento Soares
 * @author João Pedro Souza Pascon
 */

#include "util.h"

#include "math.h"

/******************************
 * FUNCOES NAO EXPOSTAS       *
 *******************************/
void reverse(char* str, uint8_t len) {
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int intToStr(uint32_t x, char str[], uint8_t d) {
    int i = 0;
    do {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    } while (x);

    while (i < d) str[i++] = '0';
    reverse(str, i);
    str[i] = '\0';
    return i;
}

/******************************
 * FUNCOES EXPOSTAS           *
 *******************************/
void espera_2us(uint32_t n) __attribute__((naked));
void espera_2us(uint32_t n) {
    asm volatile(
        "cmp r0, #0 \n\t"
        "beq espera_ret \n\t"
        "espera_loop: \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "add r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "sub r0, #1 \n\t"
        "cmp r0, #0 \n\t"
        "bne espera_loop \n\t"
        "espera_ret: \n\t"
        "bx lr"
        :
        :
        :);
}

// Converte um float em uma string com afterpoint digitos depois do ponto
void ftoa(float n, char* res, uint8_t afterpoint) {
    // Extrai a parte inteira
    int ipart = (int)n;

    // Extrai a parte em ponto flutuante
    float fpart = n - (float)ipart;

    // Converte a parte inteira para string
    int i = intToStr(ipart, res, 0);

    if (afterpoint != 0) {
        res[i] = '.';                         // Adiciona o ponto
        fpart = fpart * pow(10, afterpoint);  // Desloca a parte significativa depois do ponto

        if (fpart - (int)fpart >= 0.5) fpart += 1.0;  // Arredondamento e nao truncamento
        intToStr((int)fpart, res + i + 1, afterpoint);
    }

    return;
}
