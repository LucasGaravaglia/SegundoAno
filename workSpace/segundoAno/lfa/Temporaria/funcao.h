#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transicao{
	int EstadoAtual;
	char CaracterLido;
	int EstadoProx;
};

struct Transicao transicao[255];

int estados[50];
int num_transicoes, num_estadosFinal, EstadosFinal[5], EstadoInicial;
char alfabeto[255];

struct TransicaoAFE{
	int EstadoAtualAFE;
	char CaracterLidoAFE;
	int EstadoProxAFE[10];
};

struct TransicaoAFE transicaoAFE[255];

int estadosAFE[50];
int num_estadosAFE;
int num_transicoesAFE, num_estadosFinalAFE, EstadosFinalAFE[5], EstadoInicialAFE;
char alfabetoAFE[255];

void Carregar_Arquivo(char Arq[]);

void Carregar_ArquivoAFE( char Arq[] );

int validar_palavra( char palavra[] );

int processar_palavra(char palavra[], int estado);

int eh_final(int estado);

int prox_estado(int estadoAtual, char simbolo);

#endif
