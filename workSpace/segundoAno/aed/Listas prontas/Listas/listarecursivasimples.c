//#include "listarecursivasimples.h"
//#include <stdio.h>
//#include <stdlib.h>


//Lista* RemoveUnicoRec(Lista *l,TipoItem info){
//    Lista *temp = l;

//    if(l == NULL)               //Quando a lista for nulla ele retorna null.
//        return NULL;
//    if(l->info == info){        //Se ele achou o valor procurado
//        temp = l->prox;         //avança para o proximo ,da free na cabeça, a nova cabeça
//        free(l);
//        return temp;
//    }
//    l->prox = RemoveUnicoRec(l->prox,info); //Se a cabeça não for nulla,
//    return l;                               //ou não acho o valor ele chama a função novamente
//}

//Lista* InverteRecCaud(Lista* l){
//    Lista *aux = NULL;
//    if(VerificaLista(l))
//        return NULL;
//    if(l->prox == NULL)
//        return l;
//    aux = InsereCauda(InverteRecCaud(l->prox),l->info);
//    return aux;
//}
//Lista* InverteRecCab(Lista* l){
//    Lista *aux = NULL;
//    if(VerificaLista(l))
//        return NULL;
//    if(l->prox == NULL)
//        return l;
//    aux = insere(l->prox,l->info);
//    InverteRecCab(l->prox);
//    return aux;
//}


//Lista *ConcatListRec(Lista *l1, Lista *l2){
//    Lista *aux = NULL;
//    if(l1 == NULL )
//        return l2;
//    if(l1 == NULL && l2 == NULL)
//        return NULL;
//    aux = insere(l1,l1->info);
//    aux->prox = ConcatListRec(l1->prox,l2);
//    return aux;

//}

//Lista *MergeRec(Lista *l1, Lista *l2){
//    Lista *aux = NULL;

//    if(l1 == NULL && l2 == NULL) return NULL;
//    if(l1 == NULL) return l2;
//    if(l2 == NULL) return l1;
//    aux = insere(l1,l1->info);
//    aux->prox = insere(l2,l2->info);
//    aux->prox->prox = MergeRec(l1->prox,l2->prox);

//    return aux;
//}
