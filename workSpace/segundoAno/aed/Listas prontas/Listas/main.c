//Lista Encadeada Simples

#include <stdio.h>
#include <stdlib.h>
//#include <listadepcircular.h>
//#include "listadup.h"
#include "pilha.h"

int main(){
    pilha *f = NULL;

    f = push(f,7);
    f = push(f,6);
    f = push(f,5);
    f = push(f,4);
    f = push(f,3);
    f = push(f,2);
    f = push(f,1);

    printf("'%d'\n",topo(f));
    f = pop(f);
    printf("'%d'\n",topo(f));
    f = pop(f);
    printf("'%d'\n",topo(f));
    f = pop(f);
    printf("'%d'\n",topo(f));
    f = pop(f);
    printf("'%d'\n",topo(f));
    f = pop(f);
    printf("'%d'\n",topo(f));
    f = pop(f);
    printf("'%d'\n",topo(f));
    f = pop(f);


    printf("-------------------1\n");
    imprime(f);

    return 0;
}
