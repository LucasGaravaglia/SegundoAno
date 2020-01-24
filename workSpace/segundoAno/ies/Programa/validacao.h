#ifndef VALIDACAO_H
#define VALIDACAO_H
/* Validacao
 * Versão: 1.0
 * Ultima Modificação: 21/03/2019 - 21:54
 * Ultimo Editor: Caio
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 *
 *
 *    Funções De Checagem Auxiliares
 *
 *
 */

/* Função que checa se a string do horário possui o tamanho certo
 * ->tempo = String contendo o horário
 *<-1 para positivo e 0 para negativo
 */
int checkTimeSize(char *tempo);

/*Função que checa se a string do horário está no formato certo
 * ->tempo = String contendo o horário
 * <-1 para positivo e 0 para negativo
 */
int checkTimeFormat(char *tempo);

/*Função que checa se uma sigla está no tamanho certo
 * ->sigla = String contendo a sigla
 * <-1 para positivo e 0 para negativo
 */
int checkSigSize(char *sigla);

/*Função que checa se um caractere é uma letra maiúscula
 * ->a = Um caractere
 * <-1 para positivo e 0 para negativo
 */
int checkLetUp(char a);

/*Função que checa se uma sigla é formada apenas por letras maiúsculas
 * ->sigla = String contendo a sigla
 * <-1 para positivo e 0 para negativo
 */
int checkSigLetUp(char *sigla);

/*Função que checa se um cpf possui o tamanho certo
  * <-1 para positivo e 0 para negativo
  * ->cpf = String contendo o cpf
 */
int checkCpfSize(char *cpf);

/*Função que checa se um caractere é um número
  * ->a = Valor que vai ser checado se é ou não um número 
  * <-1 para positivo e 0 para negativo
  */
int checkNum(char a);

/*Função que checa se todos os caracteres de um cpf são números
 * ->cpf = String contendo o cpf
 * <-1 para verdadeiro e 0 para falso
 */
int checkCpfNum(char *cpf);

/*
 *
 *
 *    Funções De Checagem Principais
 *
 *
 */
 
 /*Função que checa se um horário está ou não no formato certo
 * ->tempo = String contendo o horário no formato: hh:mm
 * <-1 para positivo e 0 para negativo
 */
int checkTime(char *tempo);

/*Função que checa se uma sigla é válida
 * ->sigla = String contendo a sigla
 * <-1 para positivo e 0 para negativo
 */
int checkSig(char *sigla);

/*Função que checa se o aeroporto de destino não possui o mesmo nome do de origem
 * ->dest / orig = String com o nome do aeroporto de destino e outra com o de origem
 * <-1 para positivo e 0 para negativo
 */
int checkAirport(char *dest, char *orig);

/*Função que checa se um cpf é ou não válido
  * ->cpf = String contendo o cpf
  * <-1 para positivo e 0 para negativo
  */
int checkCpf(char *cpf);

#endif
