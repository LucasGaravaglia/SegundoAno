#include "hashingLista.h"


int hash(int k){
    return k%TAM;
}
Lista* insere(Lista *l,TipoRegistro info){
    Lista *aux = (Lista*) malloc(sizeof(Lista));
    if(l != NULL){
        aux->info = info;
        aux->ant = NULL;
        aux->prox = l;
        l->ant = aux;
    }else{
        aux->info = info;
        aux->ant = NULL;
        aux->prox = l;
    }
    return aux;
}
Lista* removelista(Lista *l,TipoChave chave){
    Lista *temp;
    if(l == NULL) return NULL;
    if(l->info.matricula == chave){
        temp = l->prox;
        temp->ant = NULL;
        free(l);
        printf("Elemento removido.\n");
        return temp;
    }
    l->prox = removelista(l->prox,chave);
    l->prox->ant = l;
    return l;
}
void show(Lista *l){
    while(l){
        printf("matricula: %d\nNome: %s\n\n",l->info.matricula,l->info.nome);
        l = l->prox;
    }
}

void inicializaTabelaHash(TabelaHash T){
    for(int i=0;i<TAM;i++){
        T[i].r = NULL;
    }
}

void inserir(TabelaHash T, TipoChave k, TipoRegistro r){
    int pos;
    pos = hash(k);
    T[pos].k = k;
    T[pos].r = insere(T[pos].r,r);
}

int buscar(TabelaHash T, TipoChave k){
    int pos;
    pos = hash(k);
    if(T[pos].r)
        return pos; 
    return -1;
}

void remover(TabelaHash T, TipoChave k){
    int pos;
    pos = buscar(T,k);
    if(k != -1)
        T[pos].r = removelista(T[pos].r,k);
    else
        printf("Elemento não encontrado.\n");
}

void showtabela(TabelaHash T){
    for(int i = 0;i<TAM;i++){
        if(T[i].r != NULL){
            printf("POSIÇÃO %d\n\n",i);
            show(T[i].r);
        }
    }
}

int main(){
    TabelaHash T;
    TipoRegistro k;

    inicializaTabelaHash(T);

    strcpy(k.nome,"Lucas Garavaglia");
    k.matricula = 28231 ;
    inserir(T,k.matricula,k);

    strcpy(k.nome,"Lucas");
    k.matricula = 28231 ;
    inserir(T,k.matricula,k);

    strcpy(k.nome,"teste");
    k.matricula = 28231 ;
    inserir(T,k.matricula,k);

    printf("ANTES DE REMOVER\n\n");
    showtabela(T);
    printf("DEPOIS DE REMOVER\n\n");
    remover(T,k.matricula);
    showtabela(T);
    return 0;
}