#ifndef INTERACAO_H
#define INTERACAO_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_cliente.h"
#include "lista_voo.h"
#include "lista_aeronave.h"
#include "controle.h"
#include "testeaeronave.h"
#include "testecliente.h"
#include "testevoo.h"




/*
 *Função que para inserção de dados (admin)
 * ->Ponteiro para Lista_Voo.
 */
Lista_Voo *insere_terminal_voo(Lista_Voo *v);

/*
 *Função que para inserção de dados (admin)
 * ->Ponteiro para Lista_Cliente.
 */
Lista_Cliente * insere_terminal_cliente(Lista_Cliente *v);

/*
 *Função que para inserção de dados (admin)
 * ->Ponteiro para Lista_Plane.
 */
Lista_Plane *insere_terminal_aeronave(Lista_Plane *v);

/*
 *Função que para alteração de dados (admin)
 * ->Ponteiro para Lista_Voo.
 */
void altera_terminal_voo(Lista_Voo *v);

/*
 *Função que para alteração de dados (admin)
 * ->Ponteiro para Lista_Cliente.
 */
void altera_terminal_cliente(Lista_Cliente *v);

/*
 *Função que para alteração de dados (admin)
 * ->Ponteiro para Lista_Plane.
 */
void altera_terminal_aeronave(Lista_Plane *v);

/*
 *Função que deleta dados (admin)
 * ->Ponteiro para Lista_Voo.
 */
Lista_Voo *deleta_terminal_voo(Lista_Voo *v);

/*
 *Função que deleta dados (admin)
 * ->Ponteiro para Lista_Cliente.
 */
Lista_Cliente *deleta_terminal_cliente(Lista_Cliente *v);

/*
 *Função que deleta dados (admin)
 * ->Ponteiro para Lista_Plane.
 */
Lista_Plane *deleta_terminal_aeronave(Lista_Plane *v);

/*
 *Função que mostra dados (admin e usuario)
 * ->Ponteiro para Lista_Voo.
 */
void mostra_terminal_voo(Lista_Voo *v);

/*
 *Função que mostra dados (adm)
 * ->Ponteiro para Lista_Cliente.
 */
void mostra_terminal_cliente(Lista_Cliente *v);

/*
 *Função que mostra dados (admn e usuario)
 * ->Ponteiro para Lista_Plane.
 */
void mostra_terminal_aeronave(Lista_Plane *v);

/*
 *Função que mostra dados de um cliente (usuario)
 * ->Ponteiro para Lista_Plane.
 */
void mostra_terminal_cliente_cliente(Lista_Cliente *lista);







#endif
