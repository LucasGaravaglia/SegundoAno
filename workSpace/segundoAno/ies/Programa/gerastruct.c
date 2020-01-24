#include "gerastruct.h"


void gera_char(int k,char *v,int p){
    int n,i,tamanho;
    srand(time(NULL)+p);
    n = rand() % 25;
    n+=65;
    tamanho=1+rand() % k;
    for(i=0;i<tamanho;i++){
    v[i] = n;
    n = rand() % 25;
    n+=97;
    }
    v[tamanho+1]= '\0';
}

int gera_erro(int n){
    srand(time(NULL)+n);
        return ((rand() % 8112331) % 2);
}

void gera_sigla(char t[],int p){
    int i,n;
        srand(time(NULL)+p);
    for(i=0;i<3;i++){
        n = rand() % 25;
        n+=65;
        t[i]=n;
    }
    t[3]='\0';
}

void gera_hora(char t[],int p){
    int n,k=50;
    srand(time(NULL)+p);
    n = rand() % 2;
    n+=48;
    t[0]=n;
    if( t[0] == k ){
        n = rand() % 2;
        n+=48;
        t[1]=n;
   }else{
         n = rand() % 9;
         n+=48;
         t[1]=n;
    }
    t[2]=':';
    n = rand() % 5;
    n+=48;
    t[3]=n;
    n = rand() % 9;
    n+=48;
    t[4]=n;
    t[5]='\0';
    }

void gera_cpf(int tamanho, char *v,int p){
    int n,i;
     srand(time(NULL)+p);
     for(i=0;i<tamanho;i++){
        n = rand() % 10;
        n+=48;
        v[i] = n;
     }
     v[tamanho]= '\0';

}

void gera_cpf_erro(int tamanho, char *v,int p){
    int n,i;
     srand(time(NULL)+p);
     tamanho = tamanho + 3 -rand()%6;
     for(i=0;i<tamanho;i++){
        n = rand() % 10;
        n+=48;
        v[i] = n;
     }
     v[tamanho]= '\0';
}

void gera_valor(int *valor, int p){
    srand(time(NULL)+p);
    (*valor) = rand() % 1000;
}

void gera_struct_voo(Flight *bom,int n,int *p,int j){
    char temp[4],temphi[6],temphf[6];

    gera_char(n,bom->prefixo,*p);(*p)+=1;
    gera_char(n,bom->nomeO,*p);(*p)+=1;
    gera_char(n,bom->tipo,*p);(*p)+=1;
    if(gera_erro(j)){
        strcpy(bom->nomeD,bom->nomeO);(*p)+=1;
    gera_char(3,bom->siglaO,*p);(*p)+=1;
    }

    gera_char(n,bom->nomeD,*p);(*p)+=1;
    gera_sigla(temp,*p);(*p)+=1;
    strcpy(bom->siglaO,temp);(*p)+=1;
        if(gera_erro(j+5)){
            gera_char(3,bom->siglaD,*p);(*p)+=1;
                }else{
                gera_sigla(temp,*p);(*p)+=1;
                strcpy(bom->siglaD,temp);(*p)+=1;
        }
    gera_hora(temphi,*p);(*p)+=1;
    strcpy(bom->horaC,temphi);(*p)+=1;
        if(!gera_erro(j)){
            gera_char(6,bom->horaP,*p);(*p)+=1;
        }else{
            gera_hora(temphf,*p);(*p)+=1;
            strcpy(bom->horaP,temphf);(*p)+=1;
     }
        gera_hora(bom->duracao,*p);(*p)+=1;
}

void gera_struct_pessoa(Client *pessoa,int n,int *p,int j){
    int temp;

        gera_char(n,pessoa->nome,*p);(*p)+=1;
        gera_char(n,pessoa->programa,*p);(*p)+=1;
        gera_char(n,pessoa->categoria,*p);(*p)+=1;
            if(gera_erro(j))
                gera_cpf_erro(11,pessoa->cpf,*p);
            else
                gera_cpf(11,pessoa->cpf,*p);
            gera_valor(&temp,*p);(*p)+=1;
            pessoa->saldo = temp;
     }

void gera_struct_aeronave(Plane *aeronave,int n, int *p){
    int temp;

    gera_char(n,aeronave->modelo,*p);(*p)+=1;
    gera_valor(&temp,p);(*p)+=1;
    aeronave->alcance = temp;
    gera_valor(&temp,p);(*p)+=1;
    aeronave->altura = temp;
    gera_valor(&temp,p);(*p)+=1;
    aeronave->banheiros = temp;
    gera_valor(&temp,p);(*p)+=1;
    aeronave->cadeiras = temp;
    gera_valor(&temp,p);(*p)+=1;
    aeronave->comprimento = temp;
    gera_valor(&temp,p);(*p)+=1;
    aeronave->envergadura = temp;
    gera_valor(&temp,p);(*p)+=1;
    aeronave->velocidadeC = temp;
}

