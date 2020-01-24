#ifndef LISTA_H
#define LISTA_H
/* Listas
 * Versão: 1.3
 * Ultima Modificação: 04/04/2019 - 08:49
 * Ultimo Editor: Levi
 */

#include "controle.h"


/*
 * Funções de lista dos voos
 */

/* Função que diz se alista eh vazia
 * ->Ponterio da cabeça da lista
 * <- retorna 1 se a lista é vazia e 0 se nao
 */
int vazia_voo(Lista_Voo * l);

/* Função que imprime a lista de voos
 * ->Ponterio da cabeça da lista
 */
void imprimir_lista_voo(Lista_Voo * l);


/* Função que insere um voo na lista de voos
 * ->Ponterio da cabeça da lista
 * ->struct Flight carregada com dados
 *<-Ponteiro para cabeça da lista
 */
Lista_Voo * inserir_lista_voo(Lista_Voo * l, Flight info);



/* Função que altera um voo da lista de voos
 * ->Ponterio da cabeça da lista
 * ->struct Flight carregada com novos dados
 * ->struct Flight a ser excluida
 *<- retorna endereço do item alterado
 */
Lista_Voo * alterar_lista_voo(Lista_Voo * l, Flight info, Flight x);




/* Função que Consulta um voo da lista de voos
 * ->Ponterio da cabeça da lista
 * ->struct Flight a ser Consultada
 * <-retorna 1 se achou o voo, 0 se nao achou
 */
int consultar_lista_voo(Lista_Voo * l, Flight info);




/* Função que Deleta um voo da lista de voos
 * ->Ponterio da cabeça da lista
 * ->struct Flight a deletada
 */
Lista_Voo * deletar_lista_voo(Lista_Voo * l, Flight info);




/*
 * Funções de lista dos clientes
 */


/* Função que diz se alista eh vazia
 * ->Ponterio da cabeça da lista
 * <- retorna 1 se a lista é vazia e 0 se nao
 */
int vazia_cliente(Lista_Cliente *l);


/* Função que insere um cliente na lista de clientes
 * ->Ponterio da cabeça da lista
 * ->struct Client carregada com dados
 *<-Ponteiro para cabeça da lista
 */
Lista_Cliente * inserir_lista_cliente(Lista_Cliente *l, Client info);



/* Função que altera um cliente da lista de clientes
 * ->Ponterio da cabeça da lista
 * ->struct Client carregada com novos dados
 * ->struct Client a ser excluida
 *<-Ponteiro para cabeça da lista
 */
Lista_Cliente * alterar_lista_cliente(Lista_Cliente *l, Client c, Client info);



/* Função que Consulta um cliente da lista de clientes
 * ->Ponterio da cabeça da lista
 * ->struct Client a ser Consultada
 */
Lista_Cliente * consultar_lista_cliente(Lista_Cliente *l, Client info);



/* Função que Deleta um cliente da lista de clientes
 * ->Ponterio da cabeça da lista
 * ->struct Cliente a ser deletada
 */
Lista_Cliente * deletar_lista_cliente(Lista_Cliente *l, Client info);



/*
 * Funções de lista das aeronaves
 */





/* Função que insere uma aeronave na lista de aeronaves
 * ->Ponterio da cabeça da lista
 * ->struct Plane carregada com dados
 *<-Ponteiro para cabeça da lista
 */
Lista_Plane * inserir_lista_plane(Lista_Plane *l, Plane info);




/* Função que altera umaeronave da lista de aeronaves
 * ->Ponterio da cabeça da lista
 * ->struct Plane carregada com novos dados
 * ->struct Plane a ser excluida
 *<-Ponteiro para cabeça da lista
 */
Lista_Plane * alterar_lista_plane(Lista_Plane *l, Plane info, Plane x);




/* Função que Consulta uma aeronave da lista de aeronaves
 * ->Ponterio da cabeça da lista
 * ->struct Plane a ser Consultada
 */
Lista_Plane * consultar_lista_plane(Lista_Plane *l, Plane info);




/* Função que Deleta uma aeronave da lista de aeronaves
 * ->Ponterio da cabeça da lista
 * ->struct PLane a  ser deletada
 */
Lista_Plane * deletar_lista_plane(Lista_Plane *l, Plane info);
/* Função que conta quantos elementos a na lista.
 * ->Lista de voo
 */
int Conta_Lista_voo(Lista_Voo *v);

/* Função que conta quantos elementos a na lista.
 * ->Lista de client
 */
int Conta_Lista_Client(Lista_Cliente *v);

/* Função que conta quantos elementos a na lista.
 * ->Lista de aeronave
 */
int Conta_Lista_Plane(Lista_Plane *v);

#endif
