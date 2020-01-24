#ifndef CAMPO_H
#define CAMPO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
// #include <conio.h>

#define ever (;;)
#define reset 102
#define aumenta 113
#define diminui 101

// #define BordaLinux 35
#define cima 119        //w
#define direita 100     //d
#define esquerda 97     //a
#define baixo 115       //s

#define espaco " "           //Restante do mapa
#define cheio "@"//"\u2591"//254           //Desenho da cobra
#define figurafruta "0"//157     //Desenho em asciii da fruta

#define TamX 80        //largura maxima do campo
#define TamY 30         //Altura maxima do campo

#define frutaX 0        //define para posicao 0 do vetor que vai guardar o eixo x da matriz onde ficara a fruta
#define frutaY 1        //define para posicao 1 do vetor que vai guardar o eixo y da matriz onde ficara a fruta

#define eixoX 0         //direita.esquerda
#define eixoY 1         //cima.baixo

#define QuinaDircima "\u2557"
#define QuinaDirbaixo "\u255d"
#define QuinaEsqcima "\u2554"
#define QuinaEsqbaixo "\u255a"

#define Retahorizontal "\u2550"
#define RetaVertical "\u2551"

void gotoxy(int x,int y);
int kbhit(void);
int getchch(void);
void criacampo();
int conferecorpo(int posicaocorpo[][1000],int BodySnakeSize);
void exibecobra(int posicaocabeca[],int fruta[],int posicaocorpo[][1000], int BodySnakeSize);
#endif