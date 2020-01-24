#ifndef DEFINES_ESTRUTURAS_H
#define DEFINES_ESTRUTURAS_H

#define TAMANHO_X 300
#define TAMANHO_Y 300

typedef struct{
    bool bomba;
    bool risco;//marcação para tela
    int quantidadeBomba;
    bool passou;//marcação para tela
    bool marcaBomba;//marcação para tela
}LOCAL;

LOCAL campoMinado[TAMANHO_X][TAMANHO_Y];
bool campoTela[TAMANHO_X][TAMANHO_Y];
int randBomb_x;
int randBomba_y;

int NumeroMaximoBombas = ((TAMANHO_X * TAMANHO_Y) * 0.1);
#endif