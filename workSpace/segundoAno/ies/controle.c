#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "controle.h"
#include <time.h>




int char_to_num(char a){
    if(a == '0') return 0;
    else if(a == '1') return 1;
    else if(a == '2') return 2;
    else if(a == '3') return 3;
    else if(a == '4') return 4;
    else if(a == '5') return 5;
    else if(a == '6') return 6;
    else if(a == '7') return 7;
    else if(a == '8') return 8;
    else if(a == '9') return 9;
    else return -9999999;
}


int to_hora(int min){
    int a,b,horas;
    a=min/60;
    b=min-a*60;
    horas=a*100+b;
}


int to_min(char *hora){
    int horas = 0;
    horas += char_to_num(hora[0])*10;
    horas += char_to_num(hora[1]);
    horas *= 60;
    horas += char_to_num(hora[3])*10;
    horas += char_to_num(hora[4]);
    return horas;
}

int status_manual(char *horaPartida, char * hora){
    int dif;
    dif = to_min(horaPartida) - to_min(hora);
    if(dif >= 60){
        return 1; //check in aberto
    }else if(dif < 60 && dif > 30){
        return 2; //check in fechado
    }else if(dif <= 30 && dif > 20){
        return 3; //embarque próximo
    }else if(dif <= 20 && dif > 10){
        return 4; //embarque imediato
    }else if(dif <= 10 && dif > 0){
        return 5; //ultima chamada
    }else if(dif <= 0 && dif >= -10){
        return 6; //partindo
    }else if(dif < -10){
        return 7; //voo encerrado
    }else{
        return -1; //Erro
    }
}

int status(char *horaPartida){
    int dif;
    time_t rawtime;
    struct tm * timeinfo;
    
      time ( &rawtime );
      timeinfo = localtime ( &rawtime );
      char a[50];
      strcpy(a,asctime (timeinfo));
      
      
      
    dif = to_min(horaPartida) - to_min(a+11);
    if(dif >= 120){
        return 1; //Previsto
    }else if(dif < 120 && dif > 60){
        return 2; //check Aberto
    }else if(dif <= 60 && dif > 45){
        return 3; //check-in Fechado
    }else if(dif <= 45 && dif > 40){
        return 4; //embarque próximo
    }else if(dif <= 40 && dif > 20){
        return 5; //embarque imediato
    }else if(dif <= 20 && dif > 10){
        return 6; //ultima chamada
    }else if(dif <= 10 && dif > 0){
        return 7; //Embarque encerrado
    }else if(dif <= 0 && dif >= -10){
        return 8; //partindo
    }else if(dif < -10){
        return 0; //voo encerrado
    }else {
        return -1; //Erro
    }
}


void showStatus(char *horaPartida){
    if(checkTimeFormat(horaPartida)){
        if(status(horaPartida) == 1){   
            printf("           Previsto          |\n");
        }else if(status(horaPartida) == 2){
            printf("        Check in aberto      |\n");
        }else if(status(horaPartida) == 3){
            printf("       Check in fechado      |\n");
        }else if(status(horaPartida) == 4){
            printf("       Embarque próximo      |\n");
        }else if(status(horaPartida) == 5){
            printf("      Embarque imediato      |\n");
        }else if(status(horaPartida) == 6){
            printf("        Ultima chamada       |\n");
        }else if(status(horaPartida) == 7){
            printf("      Embarque Encerrado     |\n");
        }else if(status(horaPartida) == 8){
            printf("           Partindo          |\n");
        }else if(status(horaPartida) == 0){
            printf("        Voo encerrado        |\n");
        }else{
            printf("Erro na função showStatus\n");
        }
    }else{
        printf("O tempo informado é inválido\n");
    }
}




char getch(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return buf;
}

char getchChar(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return buf;
}


/*
 * Funções Principais dos voos
 */

void troca_voo(Flight *a, Flight *b){
    Flight t;
    t=*a;
    *a=*b;
    *b=t;
    
    
}


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


