#include "listadup.h"

#include <stdio.h>
#include <stdlib.h>

Lista* inseredup(Lista* l, int info){
    Lista *aux = (Lista*)malloc(sizeof(Lista));

    if(l == NULL){
        l = (Lista*)malloc(sizeof(Lista));
        l->info = info;
        l->ant = NULL;
        l->prox = NULL;
        return l;
    }else{
        l->ant = aux;
        aux->info = info;
        aux->prox = l;
        aux->ant = NULL;
    }
    return aux;
}
Lista* removedup(Lista* l, int info){
    Lista *aux = l;
    while(aux->info != info && aux != NULL)
        aux = aux->prox;
    if(aux != NULL){
        if(aux == l)
            l = l->prox;
        else if(aux->prox != NULL){
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
        }else{
            aux->ant->prox = NULL;
        }
        free(aux);
    }else
        printf("Elemento não encontrado");
    return l;

}
void imprimedup(Lista* l){
    Lista *aux = l;
    while (aux){
        printf("%d\n",aux->info);
        aux = aux->prox;
    }
}

Lista* invertedup(Lista* l){
    Lista *aux = NULL;

    while(l){
        aux = inseredup(aux,l->info);
        l = l->prox;
    }
    return aux;
}

Lista* concatenadup(Lista* l1, Lista* l2){
    Lista *aux = NULL;

    while(l1){
        aux = inseredup(aux,l1->info);
        l1 = l1->prox;
    }
    while(l2){
        aux = inseredup(aux,l2->info);
        l2 = l2->prox;
    }
    aux = invertedup(aux);
    return aux;
}

Lista* mergedup(Lista* l1, Lista* l2){
    Lista *aux = NULL;

    while (l1 && l2){
        aux = inseredup(aux,l1->info);
        aux = inseredup(aux,l2->info);
        l1 = l1->prox;
        l2 = l2->prox;
    }
    while(l1){
        aux = inseredup(aux,l1->info);
        l1 = l1->prox;
    }
    while(l2){
        aux = inseredup(aux,l2->info);
        l2 = l2->prox;
    }
    return aux;
}
