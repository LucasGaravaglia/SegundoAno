#ifndef CONTROLE_H
#define CONTROLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "validacao.h"
#include "unistd.h"
#include "termios.h"

/* Controle
 * Versão: 1.1
 * Ultima Modificação: 04/04/2019 - 8:50
 * Ultimo Editor: Levi
 */



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
