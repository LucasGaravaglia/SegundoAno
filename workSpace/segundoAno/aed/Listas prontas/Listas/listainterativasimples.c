//#include <stdio.h>
//#include <stdlib.h>
//#include "listainterativasimples.h"


//int VerificaLista(Lista* novo){
//    return(novo == NULL);
//}
//Lista* insere(Lista* l,TipoItem info){
//    Lista* aux = (Lista*) malloc(sizeof(Lista));
//    aux->info = info;
//    aux->prox = l;                          //encadeia com a cabeca da lista
//    return aux;                             // retorna a nova cabeca
//}
//Lista * retira1(Lista* l,TipoItem info){
//    Lista * ant = l;                        // elemento anterior
//    Lista * p = l;                          // usado para encontrar o el    emento
//                                            // a ser retirado
//    while(p!= NULL && p->info != info) {    // localiza o elemento
//    ant = p;
//    p = p->prox;
//    }
//    if(p != NULL) {                         // elemento encontrado
//        if(p == l)                          // remoc~ao na cabeca
//            l = l->prox;                    // atualiza a cabeca
//        else                                // remoc~ao no meio
//            ant->prox = p->prox;
//        free(p);                            // libera o no do elemento removido
//    }else
//        printf("Elemento n~ao encontrado\n");
//    return l;
//}
//void ShowLista(Lista *l){
//    Lista *t;
//    t=l;
//    while(t != NULL){
//        printf("%d\n",t->info);
//        t = t->prox;
//    }
//}
//int ContaOcorrencias(Lista *l, TipoItem n){
//    Lista *aux = l;
//    int cont=0;
//    while(aux != NULL){
//        if(aux->info == n) cont ++;
//        aux = aux->prox;
//    }
//    return cont;
//}
//Lista * retiraall(Lista* l,TipoItem info){
//    Lista * ant = l;                        // elemento anterior
//    Lista * p = l;                          // usado para encontrar o elemento
//                                            // a ser retirado
//    int cont=0;
//    int i;

//    cont = ContaOcorrencias(p,info);
//    if(cont != 0) {
//        for(i=0;i<cont;i++){
//        p = l;
//        while(p->info!= info) {                       // conta quantas vezes o elemento aparece
//            ant = p;
//            p = p->prox;
//        }
//            if(p == l)                          // remoc~ao na cabeca
//                l = l->prox;                    // atualiza a cabeca
//            else                                // remoc~ao no meio
//                ant->prox = p->prox;
//            free(p);                            // libera o no do elemento removido
//        }
//    }else
//        printf("Elemento não encontrado\n");

//    return l;
//}
//void vazia(Lista *novo){
//    if(VerificaLista(novo)) printf("Lista vazia\n");
//    else ShowLista(novo);
//}
//Lista* InvertLista(Lista *novo){
//    Lista *aux = novo;
//    Lista *ant = NULL;

//    while(aux != NULL){
//        ant = insere(ant,aux->info);
//        aux = aux->prox;
//    }
//    return ant;
//}
//Lista* ConcatenaLista(Lista *l1,Lista *l2){
//    Lista *p = l1->prox;
//    Lista *ant = l1;
//    while(p!=NULL){
//        ant = p;
//        p = p->prox;
//    }
//    ant->prox = l2;
//    return l1;
//}
//Lista* MergeLista(Lista *l1,Lista *l2){
//    Lista *ant;
//    Lista *aux1 = l1;
//    Lista *aux2 = l2;
//    while(aux2 != NULL && aux1 != NULL){ //Intercala entre l1 e l2 ate que um dos dois chege em NULL
//        ant = aux1;
//        aux1 = aux1->prox;
//        ant->prox = aux2;
//        ant = aux2;
//        aux2 = aux2->prox;
//        ant->prox = aux1;
//    }                                   //O ultimo elemento da lista é sempre o NULL de l1.
//    if(aux2 != NULL){                   //caso l2 for maior que l1 ele concatena o resto de l2 na lista.
//        ant->prox = aux2;
//    }
//    return l1;
//}
//Lista* RetiraElemento(Lista *l,Lista *ant){//recebe a posição a ser tirada, e a posição anterior.
//    Lista *temp = l;
//    l = l->prox;
//    ant->prox = l;
//    free(temp);
//    return l;
//}
//Lista* EliminaRepetidos(Lista *l){
//        Lista *aux = l;
//        Lista *fixo = l;

//        if(ContaOcorrencias(fixo,fixo->info) > 1)
//            fixo = retiraall(fixo,fixo->info);
//        aux = fixo;
//        while(aux){
//            if(ContaOcorrencias(fixo,aux->info) > 1)
//                fixo = retiraall(fixo,aux->info);
//            aux = aux->prox;
//        }
//        return fixo;
//    }

    
//Lista* CriarLista(Lista *l1){
//    int n;
//    printf("Quais valores tem conjunto 1? Dige <-1> quando o conjunto acabar.\n");
//    scanf("%d",&n);
//    while(n!=-1){
//        l1 = insere(l1,n);
//        scanf("%d",&n);
//    }
//    return l1;
//}
//Lista* InsereCauda(Lista *l, TipoItem info){
//    Lista* aux = (Lista*) malloc(sizeof(Lista));
//    if(l == NULL){
//        aux->info = info;
//        aux->prox = l;
//    }else{
//        aux = l;
//        while(aux->prox != NULL){
//            aux = aux->prox;
//        }
//        aux->prox = (Lista*) malloc(sizeof(Lista));
//        aux->prox->info = info;
//        aux->prox->prox = NULL;
//    }
//    return l;
//}

//int TamanhoLista(Lista *l){
//    Lista *aux = l;
//    int i;
//    while(aux){
//        aux = aux->prox;
//    i++;
//    }
//    return i;
//}
