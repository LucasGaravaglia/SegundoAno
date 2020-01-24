#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 1000
// tamanho da tabela
typedef int TipoChave;

typedef struct {
    int matricula;
    char nome[50];
} TipoRegistro;

typedef struct {
    TipoChave k; // chave
    TipoRegistro r; // registro armazenado
    int ocupado; // indica se o slot está ocupado
} slot;

typedef slot TabelaHash[TAM];

void inicializaTabelaHash(TabelaHash T);

void inserir(TabelaHash T, TipoChave k, TipoRegistro r);
//retorna a posiçao do registro de chave k na tabela hash T
// ou -1 caso a chave nao esteja presente.

int buscar(TabelaHash T, TipoChave k);

void remover(TabelaHash T, TipoChave k);

int hash(int k);