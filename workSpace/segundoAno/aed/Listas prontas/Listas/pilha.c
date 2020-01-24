#include "pilha.h"

int vazia(pilha * st){
    return (st == NULL);
}

pilha* push(pilha* st, int info){
    pilha *aux = (pilha*)malloc(sizeof(pilha));
    aux->info = info;
    aux->prox = st;
    return aux;
}

pilha* pop(pilha* st){
    pilha *aux = st;
    st = st->prox;
    free(aux);
    return st;
}

int topo(pilha* st){
    if(vazia(st))
        return -1;
    else
        return st->info;
}

void imprime(pilha* st){
    if(vazia(st)){
        printf("Lista vazia\n");
    }else{
    while(st){
        printf("%d\n",st->info);
        st = st->prox;
        }
    }
}
