#include "exercicio2.h"
#include "string.h"


int vazia(Pilha *p){
    return (p != NULL);
}


Pilha *push(Pilha *p,char *info){
    Pilha *aux = (Pilha*)malloc(sizeof(Pilha));
    strcpy(aux->info ,info);
    aux->prox = p;
    return aux;
}
Pilha *pop(Pilha *p){
    Pilha *aux = p;
    if(vazia(p)){
    p = p->prox;
    free(aux);
    return p;
    }
    return NULL;
}

void show(Pilha *p){
    while(p!=NULL){
    printf("%s \n",p->info);
    //printf("%s\n",p->naipe);
    p=p->prox;
    }
}


Pilha* newbaralho(Pilha *p){
    int i;
    int valor;
    for(i = 0; i < 13; i++){
        valor = i+1;
        if(i == 10){
            p = push(p,"J paus\0");
            p = push(p,"J copas\0");
            p = push(p,"J espadas\0");
            p = push(p,"J ouros\0");
        }else if(i == 11){
            p = push(p,"Q paus\0");
            p = push(p,"Q copas\0");
            p = push(p,"Q espadas\0");
            p = push(p,"Q ouros\0");
        }else if(i == 12){
            p = push(p,"K paus\0");
            p = push(p,"K copas\0");
            p = push(p,"K espadas\0");
            p = push(p,"K ouros\0");
        }else{
        p = push(p,"paus\0");
        p = push(p,"copas\0");
        p = push(p,"espadas\0");
        p = push(p,"ouros\0");
        }
    }
    return p;

}
