//#include "conjuntomath.h"
//#include <stdio.h>

//int pertence(Lista *l1, int x){
//    while(l1){
//        if(x == l1->info) return 1;
//        l1 = l1->prox;
//    }
//    return 0;
//}
//Lista* UniaoListas(Lista *l1, Lista *l2){
//    Lista *aux = NULL;

//    while(l1){
//        aux = insere(aux,l1->info);
//        l1 = l1->prox;
//    }
//    while(l2){
//        if(pertence(aux,l2->info)){
//            l2 = l2->prox;
//        }else{
//            aux = insere(aux,l2->info);
//            l2 = l2->prox;
//        }
//    }

//    return aux;
//}
//Lista* IntersecaoListas(Lista *l1, Lista *l2){
//    Lista *aux = NULL;
//    while(l1){
//        if(pertence(l2,l1->info)){
//            aux = insere(aux,l1->info);
//        }
//        l1 = l1->prox;
//    }
//    return aux;

//}
//Lista* DiferencaListas(Lista *l1, Lista *l2){
//    Lista *aux = NULL;
//    Lista *temp;

//    temp = l1;
//    while (temp){
//        if(!pertence(l2,temp->info))
//            aux = insere(aux,temp->info);
//        temp = temp->prox;
//    }
//    temp = l2;
//    while(temp){
//        if(!pertence(l1,temp->info))
//            aux = insere(aux,temp->info);
//        temp = temp->prox;
//    }

//    return aux;
//}
//int esta_contido(Lista *l1, Lista *l2){
//    Lista *aux1 = l1;
//    Lista *aux2 = l2;

//    if(TamanhoLista(l2) > TamanhoLista(l1))
//        return 0;

//        while (aux2){
//            if(pertence(aux1,aux2->info)){
//                aux2 = aux2->prox;
//        }else return 0;
//    }

//    return 1;
//}
//void imprime(Lista *l){
//    while(l){
//        printf(">> %d\n",l->info);
//        l = l->prox;
//    }
//}
