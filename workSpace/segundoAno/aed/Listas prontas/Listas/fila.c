//#include <stdio.h>
//#include <stdlib.h>
//#include "fila.h"

//int vazia(Fila *f){
//    return (f->prim == NULL);
//}
//void enqueue(Fila *f, int info){
//    if(vazia(f)){
//        f->ultimo = (FilaNo*) malloc(sizeof(FilaNo));
//        f->ultimo->info = info;
//        f->prim = f->ultimo;
//    }else{
//        FilaNo *aux=NULL;
//        aux = (FilaNo*) malloc(sizeof(FilaNo));
//        aux->info = info;
//        aux->prox = NULL;
//        f->ultimo->prox = aux;
//        f->ultimo = f->ultimo->prox;
//    }
//}
//void dequeue(Fila* f){
//    FilaNo *aux = f->prim;
//    f->prim = f->prim->prox;
//    free(aux);
//}
//void imprime(Fila* f){
//    FilaNo *aux = f->prim;
//    while(aux){
//        printf("%d\n",aux->info);
//        aux = aux->prox;
//    }
//}
//void inverte(Fila* f){
//    FilaNo *aux = f->prim;
//    FilaNo *fila = f->prim;
//    FilaNo *ant = NULL;
//    FilaNo *temp = f->prim;
//    fila = fila->prox;
//    aux->prox= ant;
//    while (fila){
//        ant = aux;
//        aux = fila;
//        fila = fila->prox;
//        aux->prox = ant;
//    }
//    f->prim = f->ultimo;
//    f->ultimo = temp;
//}

