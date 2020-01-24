#ifndef CONTROLE_H
#define CONTROLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "validacao.h"

/* Controle
 * Versão: 1.1
 * Ultima Modificação: 30/03/2019 - 13:21
 * Ultimo Editor: Levi
 */


/* Função que pega um digito sem a necessidade do enter
 * -> Sem entrada
 * <- Retorna o caractere pego
 */
char getchChar();




/* Função que mostra o status de um voo na tela
 * -> horaPartida = string contendo o horário de partida de um voo
 * <- sem retorno
 */
void showStatus(char *horaPartida);


/* Função que retorna o status de um voo com base no horário atual da máquina
 * -> horaPartida = string contendo o horário de partida de um voo
 * <- 1 à 7 significando os 7 possíveis estados para o voo
 */
int status(char *horaPartida);

/* Função que retorna o status de um voo com base no desejado
 * -> horaPartida = string contendo o horário de partida de um voo
 * -> hora = string contendo o horário desejado qualquer
 * <- 1 à 7 significando os 7 possíveis estados para o voo
 */
int status_manual(char *horaPartida, char * hora);


/* Função que converte um horário string para inteiro, em minutos
 * -> hora = string contendo as horas
 * <- valor inteiro convertido em minutos
 */
int to_min(char *hora);

/* Função que converte uma quantidade de min(inteiros) em horas(inteiro)
 * -> hora = inteiro contendo a quantidade de minutos
 * <- inteiro que contem o formato da hora para ser convertido
 * em string, ATENÇÂO: valor inutil!!
 */
int to_hora(int min);

/* Função que converte um char entre 0 e 9 em inteiro
 * -> a = char a ser convertido para int
 * <- valor convertido
 */
int char_to_num(char a);

/* Função que converte um numero entre 0 e 9 em char
 * -> a = inteiro a ser convertido para char
 * <- caracter convertido
 */
char num_to_char(int a);


/* Função que troca os dados entre dois voos na lista
 * -> Ponteiro para Lista_voo
 * -> Ponteiro para Lista_voo
 */
void troca_voo(Flight *l, Flight *b);

/* Função que pega um digito sem a necessidade do enter
 * -> Sem entrada
 * <- Retorna o caractere pego
 */
char getch();



/*
 * Funções Principais dos voos
 */


/*
 * Função de atribuição
 * -> Vetor de ponteiro para Lista_Voo
 * -> Srtuct FLigth carregada com dados
 * <- Retorna 1 se deu certo, 0 se nao inseriu nada
*/
int atribui_voo(Lista_Voo * l, Flight entrada);


/*
 * imprime um voo da memoria
 * -> Struct Flight carregada com dados
*/
void imprime_voo(Flight voo);


/*
 * Funções Principais dos Clientes
 */


/*
 * Função de atribuição
 * -> Vetor de ponteiro para Lista_Cliente
 * -> Srtuct Client carregada com dados
 * <- Retorna 1 se deu certo, 0 se nao inseriu nada
*/
int atribui_cliente(Lista_Cliente * l, Client entrada);

/*
 * imprime um cliente da memoria
 * -> Struct Client carregada com dados
*/
void imprime_cliente(Client c);



/*
 * Funções Principais das aeronaves
 * 
*/


/*
 * Função de atribuição
 * -> Vetor de ponteiro para Lista_Plane
 * -> Srtuct Plane carregada com dados
 * <- Retorna 1 se deu certo, 0 se nao inseriu nada
*/
int atribui_plane(Lista_Plane * l, Plane entrada);

/*
 * imprime uma aeronave da memoria
 * -> Struct PLane carregada com dados
*/
void imprime_plane(Plane p);


#endif
