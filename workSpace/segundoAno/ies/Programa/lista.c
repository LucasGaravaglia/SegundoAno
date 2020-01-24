#include "lista.h"



/*
 * Funções de lista dos voos
 */
int vazia_voo(Lista_Voo * l){
    return (!l);
}
void imprimir_lista_voo(Lista_Voo * l){
    while(l){
        printf("%s\n", l->voo.prefixo);
        l=l->prox;
    }
}
Lista_Voo * inserir_lista_voo(Lista_Voo * l, Flight info){
    Lista_Voo * aux;
    aux=malloc(sizeof(Lista_Voo));
    if(atribui_voo(aux, info)){
        aux->prox=l;
        if(aux->prox)aux->prox->ant=aux;
        aux->ant=NULL;
        return aux;
    }else{
        free(aux);
        return l;
    }
}
Lista_Voo * alterar_lista_voo(Lista_Voo * l, Flight info, Flight x){
    while(!strstr(l->voo.prefixo,info.prefixo)){
        if(!l->prox)break;
        l=l->prox;
    }
    if(strstr(l->voo.prefixo,info.prefixo)){
        atribui_voo(l, x);
        return l;
    }
    return NULL;
    
}
int consultar_lista_voo(Lista_Voo * l, Flight info){
    while(!strstr(l->voo.prefixo,info.prefixo)){
        if(!l->prox)break;
        l=l->prox;
    }
    if(strstr(l->voo.prefixo,info.prefixo)){
        imprime_voo(l->voo);
        return 1;
    }
    return NULL;
}
Lista_Voo * deletar_lista_voo(Lista_Voo * l, Flight info){
    Lista_Voo * head=l;
    if(strstr(l->voo.prefixo,info.prefixo)){
        l=l->prox;
        free(l->ant);
        l->ant=NULL;
        return l;
    }
    while(!strstr(l->voo.prefixo,info.prefixo)){
        if(!l)break;
        l=l->prox;
    }
    if(l){
        l->ant->prox=l->prox;
        if(l->prox != NULL)l->prox->ant=l->ant;
        free(l);
        return head;
    }
    return head;
}

/*
 * Funções de lista dos clientes
 */

int vazia_cliente(Lista_Cliente * l){
    return (!l);
}
void imprimir_lista_cliente(Lista_Cliente * l){
    while(l){
        printf("%s\n", l->cliente.nome);
        l=l->prox;
    }
}
Lista_Cliente * inserir_lista_cliente(Lista_Cliente * l, Client info){
    Lista_Cliente * aux;
    aux=malloc(sizeof(Lista_Cliente));
    if(atribui_cliente(aux, info)){
        aux->prox=l;
        if(aux->prox)aux->prox->ant=aux;
        aux->ant=NULL;
        return aux;
    }else{
        free(aux);
        return l;
    }
}
Lista_Cliente * alterar_lista_cliente(Lista_Cliente * l, Client c, Client info){
    while(!strstr(l->cliente.cpf,info.cpf)){
        if(!l->prox)break;
        l=l->prox;
    }
    if(strstr(l->cliente.cpf,info.cpf)){
        atribui_cliente(l, c);
        return l;
    }
    return NULL;
}
Lista_Cliente * consultar_lista_cliente(Lista_Cliente * l, Client info){
    while(!strstr(l->cliente.cpf,info.cpf)){
        if(!l->prox)break;
        l=l->prox;
    }
    if(strstr(l->cliente.cpf,info.cpf)){
        imprime_cliente(l->cliente);
        return 1;
    }
    return NULL;
}
Lista_Cliente * deletar_lista_cliente(Lista_Cliente * l, Client info){
    Lista_Cliente * head=l;
    if(strstr(l->cliente.cpf,info.cpf)){
        l=l->prox;
        free(l->ant);
        l->ant=NULL;
        return l;
    }
    while(!strstr(l->cliente.cpf,info.cpf)){
        if(!l)break;
        l=l->prox;
    }
    if(l){
        l->ant->prox=l->prox;
        if(l->prox != NULL)l->prox->ant=l->ant;
        free(l);
        return head;
    }
    return head;
}

/*
 * Funções de lista das aeronaves
 */

int vazia_plane(Lista_Plane * l){
    return (!l);
}
void imprimir_lista_plane(Lista_Plane * l){
    while(l){
        printf("%s\n", l->aeronave.modelo);
        l=l->prox;
    }
}
Lista_Plane * inserir_lista_plane(Lista_Plane *l, Plane info){
    Lista_Plane * aux;
    aux=malloc(sizeof(Lista_Plane));
    atribui_plane(aux, info);
    aux->prox=l;
    if(aux->prox)aux->prox->ant=aux;
    aux->ant=NULL;
    return aux;
}
Lista_Plane * alterar_lista_plane(Lista_Plane *l, Plane info, Plane x){
    while(!strstr(l->aeronave.modelo,info.modelo)){
        if(!l->prox)break;
        l=l->prox;
    }
    if(strstr(l->aeronave.modelo,info.modelo)){
        atribui_plane(l, x);
        return l;
    }
    return NULL;
}
Lista_Plane * consultar_lista_plane(Lista_Plane *l, Plane info){
    while(!strstr(l->aeronave.modelo,info.modelo)){
        if(!l->prox)break;
        l=l->prox;
    }
    if(strstr(l->aeronave.modelo,info.modelo)){
        imprime_plane(l->aeronave);
        return 1;
    }
    return NULL;
}
Lista_Plane * deletar_lista_plane(Lista_Plane *l, Plane info){
    Lista_Plane * head=l;
    if(strstr(l->aeronave.modelo,info.modelo)){
        l=l->prox;
        free(l->ant);
        l->ant=NULL;
        return l;
    }
    while(!strstr(l->aeronave.modelo,info.modelo)){
        if(!l)break;
        l=l->prox;
    }
    if(l){
        l->ant->prox=l->prox;
        if(l->prox != NULL)l->prox->ant=l->ant;
        free(l);
        return head;
    }
    return head;
}


int Conta_Lista_voo(Lista_Voo *v){
    Lista_Voo *aux = v;
    int i = 0;
    while(aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}

int Conta_Lista_Client(Lista_Cliente *v){
    Lista_Cliente *aux = v;
    int i = 0;
    while(aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}

int Conta_Lista_Plane(Lista_Plane *v){
    Lista_Plane *aux = v;
    int i = 0;
    while(aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}

