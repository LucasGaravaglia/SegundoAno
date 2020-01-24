#include "listadepcircular.h"

int vaziadupCir(Lista * l){
    return (l == NULL);
}

Lista* inseredupCir(Lista* l, int info){
    Lista *aux;
    if(l == NULL){
        l = (Lista *)malloc(sizeof(Lista));
        l->info = info;
        l->prox = l;
        l->ant = l;
    return l;
    }else{
        aux = (Lista*)malloc(sizeof(Lista));
        aux->info = info;
        l->ant->prox = aux;
        aux->ant = l->ant;
        aux->prox = l;
        l->ant = aux;
    }
    return aux;
}

void imprimedupCir(Lista *l){
    Lista *parada = l;

    if(vaziadupCir(l)){
        printf("Lista vazia");
    }else{
    printf("%d\n",l->info);
    l = l->prox;
    while(l != parada){
        printf("%d\n",l->info);
        l = l->prox;
        }
    }
}
Lista* removedupCir(Lista* l, int info){
    Lista *aux = l;
    while(l->info != info)
    l = l->prox;
    aux = l;
        l->prox->ant = l->ant;
        l->ant->prox = l->prox;
        l = l->prox;
        free(aux);
        return l;
}
Lista* invertedupCir(Lista* l){
    Lista *aux = NULL;
    Lista *fixo = l;

    aux = inseredupCir(aux,l->info);
    l = l->prox;
    while (l!=fixo){
        aux = inseredupCir(aux,l->info);
        l = l->prox;
    }
    return aux;
}

Lista* concatenadupCir(Lista* l1, Lista* l2){
    Lista *fixo = l1;
    Lista *aux = NULL;

    aux = inseredupCir(aux,l1->info);
    l1 = l1->prox;
    while(l1!=fixo){
        aux = inseredupCir(aux,l1->info);
        l1 = l1->prox;
    }
    fixo = l2;
    aux = inseredupCir(aux,l2->info);
    l2 = l2->prox;
    while(l2!=fixo){
        aux = inseredupCir(aux,l2->info);
        l2 = l2->prox;
    }
    return invertedupCir(aux);
}

Lista* mergedupCir(Lista* l1, Lista* l2){
    Lista *aux = NULL;
    Lista *cpyl1 = l1;
    Lista *cpyl2 = l2;

    if(l1!=NULL && l2 != NULL){
    aux = inseredupCir(aux,l1->info);
    aux = inseredupCir(aux,l2->info);
    l1 = l1->prox;
    l2 = l2->prox;
    }else if(l1 != NULL){
        aux = inseredupCir(aux,l1->info);
        l1 = l1->prox;
        while(l1 != cpyl1){
            aux = inseredupCir(aux,l1->info);
            l1 = l1->prox;
        }
    }else{
        aux = inseredupCir(aux,l2->info);
        l2 = l2->prox;
        while(l2 != cpyl2){
            aux = inseredupCir(aux,l2->info);
            l2 = l2->prox;
        }
    }
    while(l1 != cpyl1 && l2 != cpyl2){
        aux = inseredupCir(aux,l1->info);
        aux = inseredupCir(aux,l2->info);
        l1 = l1->prox;
        l2 = l2->prox;
    }
    if(l1 != cpyl1){
        while (l1 != cpyl1){
           aux = inseredupCir(aux,l1->info);
           l1 = l1->prox;
        }
    }else if(l2 != cpyl2){
        while (l2 != cpyl2){
           aux = inseredupCir(aux,l2->info);
           l2 = l2->prox;
        }
    }
    return invertedupCir(aux);
}
