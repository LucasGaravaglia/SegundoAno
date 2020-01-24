#ifndef EXERCICIO2_H
#define EXERCICIO2_H

#include <stdio.h>
#include <stdlib.h>


typedef struct pilha{
    char info[20];
    //char naipe[8];
    struct pilha *prox;
}Pilha;


int vazia(Pilha *p);
Pilha *push(Pilha *p,char *info);
Pilha *pop(Pilha *p);
void show(Pilha *p);
Pilha* invert(Pilha *p);
Pilha* newbaralho(Pilha *p);

#endif // EXERCICIO2_H
