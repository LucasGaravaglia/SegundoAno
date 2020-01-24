#ifndef LISTACABECACAUDA_H
#define LISTACABECACAUDA_H


typedef struct no {
    int info;
    struct no * prox;
}ListaNo;
typedef struct { // estrutura para lista encadeada com cabeça e cauda
    struct no* cabeca;
    struct no* cauda;
} Lista;

void ImprimiLista(Lista *l);
int ListaVazia(Lista *l);
Lista* CriaLista();
void Insere_Cabeca(Lista *l,int info);
void Insere_Cauda(Lista *l,int info);
void RemoveCabCau(Lista *l,int info);

#endif // LISTACABECACAUDA_H
