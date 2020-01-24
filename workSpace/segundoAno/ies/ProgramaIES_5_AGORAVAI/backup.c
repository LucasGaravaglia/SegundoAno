#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cMAX 20
#define vMAX 100

typedef struct{
    char nome[20];
    int capacidade;
}aircraft;
typedef struct{
    char category[20], nome[20], milesID[20];
    int miles;
    unsigned long int cpf;
}client;
typedef struct {
    int h,m;
}time;
typedef struct{
    int Nclients;
    char from[4], to[4], id[8];
    time saida, chegada, duration;
    aircraft aviao;
}flight;

//******************* Funções secundarias dos Clientes **********************
//***************************************************************************

    /*Função que recebe o cpf do cliente e retorna seu numero na lista de clientes*/
int selecionar_cliente(client *p[], unsigned long int n){
    int i;
    for(i=0;i<cMAX;i++){
        if(p[i]!=0 && n==p[i]->cpf)return i;
    }
    return -1;
}
    /*Função que retorna o parametro a ser modifica em
     *alterar_cliente*/
int parametros_cliente(){
    char a[30];
    int c=1;

    printf("Parametro a ser alterado: ");
    scanf("%s%*c", &a);

    if(strstr(a,"nome"))return 1;
    else if (strstr(a, "cpf"))return 2;
         else if(strstr(a,"milesID"))return 3;
              else if(strstr(a,"miles"))return 4;
                   else if(strstr(a,"categoria"))return 5;
                        else {  printf("nenhum parametro selecionado\n");
                                return 0;
                        }


}
    /*Funçõ que busca o primiero ponteiro vazio no vetor.
     Busca o primeiro que possua zero, ou seja, está vazio
    e pode ser alocado.*/
int busca_cponteiro(client *p[], int n){
    int i;
    for(i=0;i<n;i++){
        if(p[i]==0)return i;
    }
    return -1;
}
    /*Função que verifica se um cpf é válido*/
int verifica_cpf(client *p[], unsigned long int n){
    int i, x;
    //regra 1: limite e minimo de numeros
    if(n > 99999999999 || n< 10000000000)return 1;

    //regra 2: verifica se nao existe outra pessoa com o mesmo cpf
    for(i=x=0;i<cMAX;i++){
        if(p[i]!=0 && p[i]->cpf==n)x++;
    }
    if(x>1)return 0;
    return 0;
}

//******************* ******************************** **********************
//******************* ******************************** **********************

//******************* Funções secundarias dos voos **********************
//***************************************************************************

    /*Função que verifica se indicador do voo está correto
    retorna 1 se possui algum erro, retorna 0 se nao possui erros*/
int verifica_id_voo(flight *voo[], char *a){
          int i, c=0;

          for(i=0;i<3;i++){
                  if(*(a+i)<'A' || *(a+i)>'Z')return 1;
              }

          for(;i<7;i++){
                  if(*(a+i)<'0' || *(a+i)>'9')return 1;
              }

          for(i=0;i<vMAX;i++){
              if(voo[i]!=0 && strstr(a, voo[i]->id))c++;
          }
          if(*(a+7))return 1;
          if(c>1)return 1;
          return 0;
      }
    /*Função que verifica se a singla do aeroporto está correta
    retorna 1 se possui algum erro, retorna 0 se nao possui erros*/
int verifica_sigla(char *a){
          int i;
          for(i=0;i<3;i++){
              if(*(a+i)<'A' || *(a+i)>'Z')return 1;

          }
          if(*(a+3))return 1;
          return 0;
      }
    /*Função que verifica se os horarios estão dentro do padrão de horas,
  minutos e segundos*/
int verifica_hora(time t){
          if(t.h>24 || t.h <0)return 1;
          if(t.m>60 || t.m <0)return 1;

          return 0;
      }
    /*Função que verifica se horarios do voo estão corretos*/
int verifica_horarios(flight *p){
          int x=0;
          if (verifica_hora(p->saida))x++;
          if (verifica_hora(p->chegada))x++;
          if(verifica_hora(p->duration))x++;
          if(p->saida.h > p->chegada.h)x++;

          if(x)return 1;
          else return 0;

      }
    /*Função que retorna o parametro a ser modifica em
     *alterar_voo*/
int parametros_voo(){
    char a[30];
    int c=1;

    printf("Parametro a ser alterado: ");
    scanf("%s%*c", &a);

    if(strstr(a,"indicador"))return 1;
    else if (strstr(a, "origem"))return 2;
         else if(strstr(a,"destino"))return 3;
              else if(strstr(a,"horarios"))return 4;
                   else if(strstr(a,"aeronave"))return 5;
                        else if (strstr(a, "capaciade_aeronave"))return 6;
                             else if(strstr(a,"npassageiros"))return 7;
                                  else {printf("nenhum parametro selecionado\n");
                                        return 0;
                                        }
}
    /*Funçõ que busca o primiero ponteiro vazio no vetor.
      Busca o primeiro que possua zero, ou seja, está vazio
      e pode ser alocado.*/
int busca_vponteiro(flight *voo[], int n){
    int i;
    for(i=0;i<n;i++){
        if(voo[i]==0)return i;
    }
    return -1;
}
    /*Função que retorna posição do voo na lista de vetor,
     *de acordo com seu indicador*/
int selecionar_voo(flight *voo[], char *a){
    int i;
    for(i=0;i<vMAX;i++){
        if(voo[i]!=0 && strstr(voo[i]->id, a))return i;
    }

    return -1;
}
//******************* ******************************** **********************
//******************* ******************************** **********************

//======================================================================
//==============  Funções principais dos clientes ======================

   /* Inserindo um novo cliente.
      Ler e guarda os seguintes dados: Nome, cpf, id de millhagem,
      qtd  de milhas e categoria.    */
int inserir_cliente(client *p[], int *nclient){
    int n;
    n=busca_cponteiro(p, cMAX);
    if(n==-1){
        printf("Limite de clientes Excedido\n");
        return 0;
    }
    p[n]=malloc(sizeof(client));
    printf("-> Inserir Cliente\n");

    printf("Nome: ");
    scanf("%[^\n]", p[n]->nome);

    printf("CPF: ");
    scanf("%lu%*c", &p[n]->cpf);
    while(verifica_cpf(p, p[n]->cpf)){
        printf("CPF Invalido ou Já existente\n");
        scanf("%lu%*c", &p[n]->cpf);
    }

    printf("Programa de milhagem: ");
    scanf("%s", p[n]->milesID);

    printf("Saldo do milhas: ");
    scanf("%d%*c", &p[n]->miles);

    printf("Categoria:");
    scanf("%s", p[n]->category);

    (*nclient)++;
    printf("Cliente Inserido\n");
    return 0;
}
   /* Deletando um cliente.
      Desaloca o espaço que ele ocupava na memoria.
      Caso o cpf inserido nao correponda a nunhum cliente
      ou caso nao exitam clientes alocados, volta-se ao menu principal*/
int deletar_cliente(client *p[], int *nclient){
    unsigned long int temp;
    int n=0;

    printf("-> Deletar Cliente\n");
    printf("Insira o CPF:  ");
    scanf("%lu", &temp);
    n=selecionar_cliente(p, temp);

    if(n==-1){
        printf("Cliente nao encontrado\n");
        return 0;
    }


   printf("Cliente %lu eliminado\n", p[n]->cpf);
   free(p[n]);
   p[n]=0;
   (*nclient)--;


    return 0;

}
   /*Alterando um cliente.
      Lê um CPF, que utiliza para selecionar o cliente, logo, lê
      o parâmetro a ser alterado.
      Caso o cpf inserido nao correponda a nunhum cliente
      ou caso nao exitam clientes alocados, volta-se ao menu principal*/
int alterar_cliente(client *p[], int nclient){
    int n;
    unsigned long int temp;

    printf("-> Alterar Cliente\n");
    printf("Insira o CPF: ");
    scanf("%lu%*c", &temp);
    n=selecionar_cliente(p,temp);

    if(n==-1){
        printf("Cliente nao encontrado\n");
        return 0;
    }

    switch(parametros_cliente()){
    case (1): printf("nome: ");
              scanf("%[^\n]", p[n]->nome);
              printf("nome alterado\n");
              break;
    case (2): printf("Cpf: ");
              scanf("%lu", &p[n]->cpf);
              while(p[n]->cpf > 99999999999 || p[n]->cpf< 10000000000){
                  printf("CPF Invalido\n");
                  scanf("%lu", &p[n]->cpf);
              }
              printf("CPF alterado \n");
              break;
    case (3): printf("Programa de milhagem: ");
              scanf("%s", p[n]->milesID);
              printf("Programa de milhagem alterado\n");
              break;
    case (4): printf("miles: ");
              scanf("%d%*c", &p[n]->miles);
              printf("miles alterado\n");
              break;
    case (5): printf("Categoria: ");
              scanf("%[^\n]%*c", p[n]->category);
              printf("categoria alterada\n");
              break;
    }
    return 0;
}
   /*Consultando um cliente.
      Lê um cpf, que utiliza para selecionar o cliente.
      Logo, imprime todos os dados desse cliente.
      Caso o cpf inserido nao correponda a nunhum cliente
      ou caso nao exitam clientes alocados, volta-se ao menu principal*/
int consultar_cliente(client *p[]){
    int n;
    unsigned long int temp;

    printf("-> Consultar Cliente\n");
    printf("Insira o CPF:  ");
    scanf("%lu", &temp);
    n=selecionar_cliente(p,temp);

    if(n==-1){
        printf("Cliente nao encontrado\n");
        return 0;
    }

    printf("Nome: %s\n", p[n]->nome);
    printf("Cpf: %lu\n",p[n]->cpf );
    printf("Programa de Milhagem: %s\n", p[n]->milesID);
    printf("miles: %d\n", p[n]->miles );
    printf("Categoria: %s\n", p[n]->category);
    return 0;
}

//========================================================================
//================  Funções principais dos Voos =====+====================

    /*Função que lê os dados do voo e alloca memoria para eles,
    alem de verificar se nenhum deles infringe uma regra de escrita*/
int inserir_voo(flight *voo[], int *nvoo){
    int c=0, i, n;

    printf("-> Inserir_voo\n");

    n=busca_vponteiro(voo, vMAX);
    if(n==-1){
        printf("Limite de voos Excedido\n");
        return 0;
    }
    voo[n]=malloc(sizeof(flight));

        printf("Indicador: ");
        scanf("%[^\n]", voo[n]->id);
                    //verifica se os dados inseridos estão corretos
                    while(verifica_id_voo(voo, voo[n]->id)){
                        printf("Incorreto ou Já existente\n Insira novamente:  ");
                        scanf("%s", voo[n]->id);
                    }




        printf("Sai de: ");
        scanf("%s", voo[n]->from);

                //verifica se os dados inseridos estão corretos
                while (verifica_sigla(voo[n]->from)){
                    printf("Incorreto\n Insira Novamente: ");
                    scanf("%s", voo[n]->from);
                }

        printf("Vai para: ");
        scanf("%s", voo[n]->to);
                 //verifica se os dados inseridos estão corretos
                 while (verifica_sigla(voo[n]->to)){
                        printf("Incorreto\n Insira Novamente: ");
                        scanf("%s", voo[n]->to);
                  }

        printf("Horario de saida: ");
        scanf("%d%*c%d", &voo[n]->saida.h,&voo[n]->saida.m);
        printf("Horario de Chegada: ");
        scanf("%d%*c%d", &voo[n]->chegada.h,&voo[n]->chegada.m);
        printf("Duração do voo: ");
        scanf("%d%*c%d%*c", &voo[n]->duration,&voo[n]->duration.m);
        //verifica se os dados inseridos estão corretos
                 while(verifica_horarios(voo[n])){
                    printf("Incorreto\n Insira Novamente:");

                    printf("Horario de saida: ");
                    scanf("%d%*c%d", &voo[n]->saida.h,&voo[n]->saida.m);

                    printf("Horario de Chegada: ");
                    scanf("%d%*c%d", &voo[n]->chegada.h,&voo[n]->chegada.m);

                    printf("Duração do voo: ");
                    scanf("%d%*c%d%*c", &voo[n]->duration,&voo[n]->duration.m);
                 }

        printf("Aeronave: ");
        scanf("%[^\n]", voo[n]->aviao.nome);


        printf("Capacidade da Aeronave: ");
        scanf("%d", &voo[n]->aviao.capacidade);


        printf("Quantidade de passageiros: ");
        scanf("%d", &voo[n]->Nclients);

        while(voo[n]->Nclients > voo[n]->aviao.capacidade){
            printf("Ultrapassa o limite da aeronave\n Insira novamente: ");
            scanf("%d", &voo[n]->Nclients);
        }


    printf("Voo Inserido com Sucesso\n");


        (*nvoo)++;
        return 0;
}
    /*Função que elimina um voo da memoria*/
int deletar_voo(flight *voo[], int *n){
    char a[20];
    int i;

    printf("-> Deletar Voo\n");
    printf("Insira o Indicador do voo :");
    scanf("%s", a);
    i=selecionar_voo(voo, a);

    if(i==-1){
        printf("voo nao encontrado\n");
        return 0;
    }

    printf("voo %s deletado\n", voo[i]->id);
    free(voo[i]);

    voo[i]=0;

    (*n)--;
    return 0;
}
    /*Consultando um voo.
    Lê um inidador, que utiliza para selecionar o voo.
    Logo, imprime todos os dados desse voo.
    Caso o indicador inserido nao correponda a nunhum voo
    ou caso nao exitam voos alocados, volta-se ao menu principal*/
int consultar_voo(flight *voo[], int *n){
    char temp[20];
    int i, c=0;

    printf("-> Consultar Voo\n");
    printf("Insira o indicador: ");
    scanf("%s", temp);
    printf("indicador selecionado é %s\n", temp);
    i=selecionar_voo(voo, temp);


    if(i==-1){
        printf("voo nao encontrado\n");
        return 0;
    }


    printf("    Indicador: %s \n", voo[i]->id);
    printf("    Origem: %s", voo[i]->from);
    printf("    Saida: %d:%d \n", voo[i]->saida.h, voo[i]->saida.m);
    printf("    Destino: %s", voo[i]->to);
    printf("    Chegada: %d:%d \n", voo[i]->chegada.h, voo[i]->chegada.m);
    printf("    Duração: %d:%d \n", voo[i]->duration.h, voo[i]->duration.m);
    printf("    N de Passageiros: %d\n", voo[i]->Nclients);
    printf("    Aeronave: %s", voo[i]->aviao.nome);
    printf("    Capacidade da Aeronave: %d\n", voo[i]->aviao.capacidade);


    return 0;
}

int alterar_voo(flight *voo[]){
    char a[20];
    int i;

    printf("-> alterar Voo\n");
    printf("Indicador do voo: ");
    scanf("%s%*c", a);
    i=selecionar_voo(voo, a);

    if(i==-1){
        printf("voo nao encontrado\n");
        return 0;
    }

    switch(parametros_voo()){
    case (1):printf("Novo Indicador: ");
             scanf("%[^\n]%*c", voo[i]->id);


             //verifica se os dados inseridos estão corretos
             while(verifica_id_voo(voo, voo[i]->id)){
             printf("Incorreto ou Já existente\n Insira novamente:  ");
             scanf("%s", voo[i]->id);
             }

             printf("indicador alterado\n");
             break;
    case (2):printf("Nova Origem: ");
             scanf("%s", voo[i]->from);
             //verifica se os dados inseridos estão corretos
             while (verifica_sigla(voo[i]->from)){
                 printf("Incorreto\n Insira Novamente: ");
                 scanf("%s", voo[i]->from);
             }
             printf("Origem alterada \n");
             break;
    case (3):printf("Novo destino: ");
             scanf("%s", voo[i]->to);
             //verifica se os dados inseridos estão corretos
             while (verifica_sigla(voo[i]->to)){
                  printf("Incorreto\n Insira Novamente: ");
                  scanf("%s", voo[i]->to);
             }
             printf("Destino alterado\n");
             break;
    case (4):printf("Novo Horario de saida: ");
             scanf("%d%*c%d", &voo[i]->saida.h,&voo[i]->saida.m);
             printf("Novo Horario de Chegada: ");
             scanf("%d%*c%d", &voo[i]->chegada.h,&voo[i]->chegada.m);
             printf("Nova Duração do voo: ");
             scanf("%d%*c%d%*c", &voo[i]->duration,&voo[i]->duration.m);
             //verifica se os dados inseridos estão corretos
             while(verifica_horarios(voo[i])){
                  printf("Incorreto\n Insira Novamente:");
                  printf("Novo Horario de saida: ");
                  scanf("%d%*c%d", &voo[i]->saida.h,&voo[i]->saida.m);
                    printf("Novo Horario de Chegada: ");
                    scanf("%d%*c%d", &voo[i]->chegada.h,&voo[i]->chegada.m);
                    printf("Nova Duração do voo: ");
                    scanf("%d%*c%d%*c", &voo[i]->duration,&voo[i]->duration.m);
                 }
             printf("Horarios do voo alterados\n");
             break;
    case (5):printf("Nova Aeronave: ");
             scanf("%[^\n]", voo[i]->aviao.nome);
             printf("Aeronave alterada\n");
             break;
    case (6):printf("Nova Capacidade da Aeronave: ");
             scanf("%d", &voo[i]->aviao.capacidade);
             printf("Capacidade da aeronave alterada\n");
             break;
    case (7):printf("Quantidade de passageiros: ");
             scanf("%d", &voo[i]->Nclients);
             while(voo[i]->Nclients > voo[i]->aviao.capacidade){
                 printf("Ultrapassa o limite da aeronave\n Insira novamente: ");
                 scanf("%d", &voo[i]->Nclients);
             }
             printf("Qtd de passageiros alterada\n");
             break;/**/
    }


    return 0;
}

//========================================================================
//========================================================================
//======================== Outras Funções ================================

void libera(client *p[], int nclient, flight *voo[], int nvoo){
    int i;
    for(i=0;i<nclient;i++)free(p[i]);
    for(i=0;i<nvoo;i++)free(voo[i]);
}
int ler_comando(int *x){
    char temp[20];
    scanf("%s%*c", temp);
    if (strstr(temp,"inserir_cliente"))return 1;
    else if (strstr(temp,"deletar_cliente"))return 2;
         else if (strstr(temp,"alterar_cliente"))return 3;
              else if (strstr(temp,"consultar_cliente"))return 4;
                   else if(strstr(temp,"inserir_voo"))return 5;
                        else if(strstr(temp,"deletar_voo"))return 6;
                             else if(strstr(temp,"consultar_voo"))return 7;
                                  else if(strstr(temp,"alterar_voo"))return 8;
                                        else if (strstr(temp,"finalizar_programa"))
                                                {*x=0;
                                                return 9;}

    return 0;
}
void zera_vetor(client *p[],int c, flight *voo[], int v){
    int i;
    for(i=0;i<c;i++){
        p[i]=0;
    }
    for(i=0;i<v;i++){
        voo[i]=0;
    }
}

int main (){
    client *p[cMAX];
    int nclient=0, nvoo=0, x=1;
    flight *voo[vMAX];
    zera_vetor(p,cMAX,voo,vMAX);

    printf("--> Menu  Principal \n");
    while(x){

            switch (ler_comando(&x)){
            case (1):inserir_cliente(p, &nclient);
                     break;

            case (2):deletar_cliente(p, &nclient);
                     break;

            case (3):alterar_cliente(p, nclient);
                     break;

            case (4):consultar_cliente(p);
                     break;

            case (5):inserir_voo(voo, &nvoo);
                     break;

            case (6):deletar_voo(voo, &nvoo);
                     break;

            case (7):consultar_voo(voo, &nvoo);
                     break;

            case (8):alterar_voo(voo);
                     break;

            case (9):printf("\n\n    Programa Encerrado\n");
                     x=0;
            }

            printf("--> Menu  Principal \n");

}

    libera(p, nclient, voo, nvoo);
    return 0;
}
