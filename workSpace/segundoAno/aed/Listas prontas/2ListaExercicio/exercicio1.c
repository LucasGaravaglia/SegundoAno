//#include "exercicio1.h"

//#include <stdio.h>
//#include <stdlib.h>
//#define ever (;;)


//int vazia(Pilha *p){
//    return (p != NULL);
//}


//Pilha *push(Pilha *p,int info){
//    Pilha *aux = (Pilha*)malloc(sizeof(Pilha));
//    aux->info = info;
//    aux->prox = p;
//    return aux;
//}
//Pilha *pop(Pilha *p){
//    Pilha *aux = p;
//    if(vazia(p)){
//    p = p->prox;
//    free(aux);
//    return p;
//    }
//    return NULL;
//}

//void show(Pilha *p){
//    while(p!=NULL){
//    printf("%d\n",p->info);
//    p=p->prox;
//    }
//}

//void exercicio1(){
//    char temp;
//    int resultado = 0;

//    p = push(p,3);
//    for ever{
//        printf("-----------------\n");
//        show(p);
//        printf("-----------------\n");
//        scanf("%c%*c",&temp);
//        if(temp == '*'){
//            resultado = 1;
//            while(p){
//                resultado *= (p->info);
//                p = pop(p);
//            }
//            if(resultado != 0)
//            p = push(p,resultado);
//        }else if(temp == '+'){
//            resultado = 0;
//            while(p){
//                resultado += (p->info);
//                p = pop(p);
//            }
//            if(resultado != 0)
//            p = push(p,resultado);

//        }else if(temp == '-'){
//            resultado = (p->info);
//            p = pop(p);
//            while(p){
//                resultado -= (p->info);
//                p = pop(p);
//            }
//            if(resultado != 0)
//            p = push(p,resultado);
//        }else if(temp == '/'){
//            resultado = (p->info);
//            p = pop(p);
//            while(p){
//                resultado /= (p->info);
//                p = pop(p);
//            }
//            if(resultado != 0)
//            p = push(p,resultado);
//        }else
//            p = push(p,temp-'0');
//        system("clear");
//    }
//}
