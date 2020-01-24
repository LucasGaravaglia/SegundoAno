#include "controle.h"



/*
 * Funções Principais dos voos
 */


int atribui_voo(Lista_Voo * l, Flight entrada){
    int x=0;
    if(!checkTime(entrada.horaP))x++;
    if(!checkTime(entrada.horaC))x++;
    if(!checkTime(entrada.duracao))x++;
    if(!checkSig(entrada.siglaD))x++;
    if(!checkSig(entrada.siglaO))x++;
    if(!checkAirport(entrada.nomeD,entrada.nomeO))x++;
    
    
    if(!x){
    
    
    l->voo.prefixo=malloc(strlen(entrada.prefixo)*sizeof(char)+1);
    strcpy(l->voo.prefixo, entrada.prefixo);
    
    l->voo.nomeO=malloc(strlen(entrada.nomeO)*sizeof(char)+1);
    strcpy(l->voo.nomeO, entrada.nomeO);
    
    l->voo.nomeD=malloc(strlen(entrada.nomeD)*sizeof(char)+1);
    strcpy(l->voo.nomeD, entrada.nomeD);
    
    l->voo.tipo=malloc(strlen(entrada.tipo)*sizeof(char)+1);
    strcpy(l->voo.tipo, entrada.tipo);
        
    strcpy(l->voo.siglaD, entrada.siglaD);
    strcpy(l->voo.siglaO,entrada.siglaO);
    strcpy(l->voo.horaP, entrada.horaP);
    strcpy(l->voo.horaC, entrada.horaC);
    strcpy(l->voo.duracao, entrada.duracao);
    return 1;
    }
    return 0;
    
}

void imprime_voo(Flight voo){
    printf("    Prefixo: %s\n", voo.prefixo);
    printf("    Origem: %s", voo.nomeO);
    printf("    %s\n", voo.siglaO);
    printf("    Destino: %s", voo.nomeD);
    printf("    %s\n", voo.siglaD);
    printf("    Sai: %s", voo.horaP);
    printf("    Chega: %s\n", voo.horaC);
    printf("    Duração: %s\n", voo.duracao);
    printf("    Aeronave: %s\n", voo.tipo);
    printf("---------------------------------------\n");
    
}


/*
 * Funções Principais dos Clientes
 */

int atribui_cliente(Lista_Cliente * l, Client entrada){
    if(checkCpf(entrada.cpf)){
    l->cliente.nome=malloc(strlen(entrada.nome)*sizeof(char)+1);
    l->cliente.programa=malloc(strlen(entrada.programa)*sizeof(char)+1);
    l->cliente.categoria=malloc(strlen(entrada.categoria)*sizeof(char)+1);
    
    l->cliente.saldo = entrada.saldo;
    strcpy(l->cliente.nome,entrada.nome);
    strcpy(l->cliente.programa, entrada.programa);
    strcpy(l->cliente.cpf,entrada.cpf);
    strcpy(l->cliente.categoria, entrada.categoria);
    
    return 1;
    }
    return 0;
}
void imprime_cliente(Client c){
    printf("    Nome: %s\n", c.nome);
    printf("    CPF: %s\n", c.cpf);
    printf("    Programa: %s\n", c.programa);
    printf("    Milhagem: %d\n", c.saldo);
    printf("    Categoria: %s\n", c.categoria);
    printf("---------------------------------------\n");
    
}



/*
 * Funções Principais das aeronaves
 */
 
 
int atribui_plane(Lista_Plane * l, Plane entrada){
    l->aeronave.modelo=malloc(strlen(entrada.modelo)*sizeof(char)+1);
    strcpy(l->aeronave.modelo,entrada.modelo);
    l->aeronave.alcance=entrada.alcance;
    l->aeronave.altura=entrada.altura;
    l->aeronave.banheiros=entrada.banheiros;
    l->aeronave.cadeiras=entrada.cadeiras;
    l->aeronave.comprimento=entrada.comprimento;
    l->aeronave.envergadura=entrada.envergadura;
    l->aeronave.velocidadeC=entrada.velocidadeC;
    return 1;
}

void imprime_plane(Plane p){
    printf("    Modelo: %s\n", p.modelo);
    printf("    Alcance: %d\n", p.alcance);
    printf("    Altura: %d\n", p.altura);
    printf("    Banheiros: %d\n", p.banheiros);
    printf("    Assentos: %d\n", p.cadeiras);
    printf("    Comprimento: %d\n", p.comprimento);
    printf("    Envergadura: %d\n", p.envergadura);
    printf("    Velocidade: %d\n", p.velocidadeC);
    printf("---------------------------------------\n");
    
   
}


