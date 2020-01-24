#ifndef MENUS_H
#define MENUS_H
/* Menus
 * Versão: 2.0
 * Ultima Modificação: 12/04/2019 - 20:00
 * Ultimo Editor: Caio
 */

#include "grafico.h"

/*
 *
 * Funções auxiliares para os menus
 * 
 */
 
/* Função que pega um digito sem a necessidade do enter
 * -> Sem entrada
 * <- Retorna o caractere pego
 */
char getchChar();

/* Função auxiliar que ajuda a movimentação no menu
 * ->b = Ponteiro para variavel de controle,a = valor digitado, primeiro = primeiro elemento do menu e ultimo = ultimo elemento do menu
 * <- Retorna 1 caso o caractere seja enter e 0 caso não seja
 */
int menu_movment(int a, int *b, int primeiro, int ultimo);

/*  
 * 
 * Funções principais dos menus
 *
 */
 
/* Função que mostra na tela o menu do usuário
 * -> Variavel de controle do menu
 * <- Sem retorno
 */
void menu_usuario(int *var);

/* Função que mostra na tela o menu do administrador
 * -> Variavel de controle do menu
 * <- Sem retorno
 */
void menu_adm(int *var);

/* Função que mostra na tela o menu base
 * -> Variavel de controle do menu
 * <- Sem retorno
 */
void menu_base(int *var);

/* Função que mostra na tela o menu de testes
 * -> Variável de controle do menu
 * <- Sem retorno
 */
void menu_testes(int *var);

/* Função que mostra na tela o menu de cadastro
 * -> Variável de controle do menu e variável de controle de cadastro
 * <- Sem retorno
 */
void menu_cadastro(int *var, int IAR); //IAR = inserir = 0, alterar = 1 ou remover = 2

/* Função que mostra na tela o menu de funções de administrador
 * -> Variável de controle de menu
 * <- Sem retorno
 */
void menu_func_adm(int *var);

/* Função que executa os menus
 * -> Sem entrada
 * <- Sem retorno
 */
void menu_decider();
#endif
