#include <stdio.h>
#include <time.h>
#include "campo.h"


void SetBombas(LOCAL *campo[]){
    for(int i=0;i<NumeroMaximoBombas;i++){
        srand(time(NULL));
        randBomb_x = (rand()%TAMANHO_X);
        randBomba_y = (rand()%TAMANHO_Y);
        campo[randBomb_x][randBomba_y].bomba = true;
    }
}

void SetCampo(LOCAL *campo[],bool *campoTela[]){
    for(int i=0;i<TAMANHO_X;i++){
        for(int j=0;j<TAMANHO_Y;j++){
            campoTela[i][j] = false;
            campo[i][j].quantidadeBomba = 0;
            campo[i][j].passou = false; 
            campo[i][j].risco = false;
            campo[i][j].marcaBomba = false; 
            if(i > 0 && j > 0 && campo[i-1][j-1].bomba){
                campo[i][j].quantidadeBomba++;
            }
            if(i > 0 && campo[i-1][j].bomba){
                campo[i][j].quantidadeBomba++;
            }
            if(i > 0 && j < TAMANHO_Y && campo[i-1][j+1].bomba){
                campo[i][j].quantidadeBomba++;
            }
            if(j < TAMANHO_Y && campo[i][j+1].bomba){
                campo[i][j].quantidadeBomba++;
            }
            if(j > 0 && campo[i][j-1].bomba){
                campo[i][j].quantidadeBomba++;
            }
            if(i < TAMANHO_X && j < TAMANHO_Y && campo[i+1][j+1].bomba){
                campo[i][j].bomba++;
            }
            if(i < TAMANHO_X && j > 0 && campo[i+1][j-1].bomba){
                campo[i][j].quantidadeBomba++;
            }
            if(i < TAMANHO_X && campo[i+1][j].bomba){
                campo[i][j].quantidadeBomba++;
            }
            if(campo[i][j].quantidadeBomba != 0){
                campo[i][j].risco = true;
            }
        }
    }
}

bool start(){
    
}



