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

typedef struct no{
    TipoRegistro info;
    struct no *prox;
    struct no *ant;
} Lista;

typedef struct {
    TipoChave k; // chave
    Lista *r; // registro armazenado
} slot;

typedef slot TabelaHash[TAM];

void inicializaTabelaHash(TabelaHash T);

void inserir(TabelaHash T, TipoChave k, TipoRegistro r);
//retorna a posiçao do registro de chave k na tabela hash T
// ou -1 caso a chave nao esteja presente.

int buscar(TabelaHash T, TipoChave k);

void remover(TabelaHash T, TipoChave k);

int hash(int k);

//Funçoes lista
Lista* removelista(Lista *l,TipoChave info);
Lista* insere(Lista *l,TipoRegistro info);
void show(Lista *l);