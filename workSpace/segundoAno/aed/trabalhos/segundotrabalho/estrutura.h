#ifndef ESTRUTURA_H
#define ESTRUTURA_H


typedef struct{
    int codigo;
    char titulo[200];
    char autor[200];
    int NumExemplares;
}livro;

typedef struct{
    livro info;
    int prox;
}no;

typedef struct lis{
    livro info;
    struct lis *prox;
}Lista;

typedef struct folha{
    int info;
    struct folha *dir;
    struct folha *esq;
}Arvore;

typedef struct{
    int codigo;
    int ocupado;
}ArvoreArquivo;

typedef struct{
    int pos_livre;
    int pos_topo;
    int pos_cabeca;
}cabecalho;

#endif