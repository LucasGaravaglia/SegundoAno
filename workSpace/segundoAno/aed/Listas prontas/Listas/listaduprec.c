#include "listaduprec.h"
#include <stdio.h>
#include <stdlib.h>


Lista* inseredupRec(Lista* l, int info){
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

Lista* RemoveUnicoDupRec(Lista *l,int info){
    Lista *aux = NULL;

    if(l == NULL){
        printf("Elemento não encontrado");
        return l;
    }
    if(l->info == info){
        if(l->prox == NULL){
            return NULL;
        }
        if(l->ant != NULL){
            l->prox->ant = l->ant;
            aux = l;
            l = l->prox;
            free(aux);
        }else{
            l = l->prox;
            free(l->ant);
        }
    return l;
    }
    l->prox = RemoveUnicoDupRec(l->prox,info);
}
Lista* UltimoElementoListaRec(Lista *l){
    while (l->prox){
        l = l->prox;
    }
    return l;
}

Lista* InverteDupRec(Lista* l){
    Lista *aux = NULL;
    if(l == NULL)
        return NULL;
    if(l->ant == NULL)
        return l;
    aux = inseredupRec(InverteDupRec(l->ant),l->info);
    return aux;
    }

Lista* ConcatListDupRec(Lista *l1, Lista *l2){
    Lista *aux = NULL;

    if(l1 == NULL) return l2;
    if(l1 == NULL && l2 == NULL) return NULL;
    aux = inseredupRec(ConcatListDupRec(l1->prox,l2),l1->info);
    return aux;
}
Lista* MergeDupRec(Lista *l1, Lista *l2){
    Lista *aux;
    if(l1 == NULL && l2 == NULL) return NULL;
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    aux = inseredupRec(l1,l1->info);
    aux->prox = inseredupRec(l2,l2->info);
    aux->prox->prox = MergeDupRec(l1->prox,l2->prox);
    return aux;
}
