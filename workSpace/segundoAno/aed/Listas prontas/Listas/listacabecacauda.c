#include "listacabecacauda.h"
#include <stdio.h>
#include <stdlib.h>


void ImprimiLista(Lista *l){
    ListaNo *aux = l->cabeca;

    while(aux){
        printf("%d\n",aux->info);
        aux = aux->prox;
    }
}
int ListaVazia(Lista *l){
    return (l->cabeca == NULL);
}


Lista* CriaLista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->cabeca = l->cauda = NULL;
    return l;
}
void Insere_Cabeca(Lista *l, int info){
    ListaNo *aux = (ListaNo*) malloc(sizeof(ListaNo));

    if(ListaVazia(l)){
        aux->info = info;
        l->cabeca = aux;
        l->cauda = aux;
        aux->prox = NULL;
    }else{
        aux->info = info;
        aux->prox = l->cabeca;
        l->cabeca = aux;
    }
}
void Insere_Cauda(Lista *l,int info){
    ListaNo *aux = (ListaNo*) malloc(sizeof(ListaNo));

    if(ListaVazia(l)){
        aux->info = info;
        l->cabeca = aux;
        l->cauda = aux;
        aux->prox = NULL;
    }else{
        aux->info = info;
        aux->prox = NULL;
        l->cauda->prox = aux;
        l->cauda = aux;
    }
}

void RemoveCabCau(Lista *l,int info){
    ListaNo *aux;
    ListaNo *temp;

    if(l->cabeca->info == info){
        aux = l->cabeca;
        l->cabeca = l->cabeca->prox;
        free(aux);

    }else if(l->cauda->info == info){
        aux = l->cabeca;
        while(aux->prox->prox != NULL)
            aux = aux->prox;
        temp = l->cauda;
        l->cauda = aux;
        free(temp);
        l->cauda->prox = NULL;
    }else{
    aux = l->cabeca;
    while( aux->info != info && aux->prox != NULL ){
        temp = aux;
        aux = aux->prox;
    }
    if(aux->prox == NULL) printf("Elemento não encontrado\n");
    temp->prox = aux->prox;
    free(aux);
    }

}

