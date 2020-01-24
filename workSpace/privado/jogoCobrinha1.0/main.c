#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "campo.h"


int main(){
    srand(time(NULL));
    int controle = cima;//controle começa para cima
    int flag = cima;//flag comeca para cima
    int posicaocabeca[2];
    int flagcabeca[2];
    int fruta[2];
    int BodySnakeSize = -1;
    int posicaocorpo[2][1000];

    posicaocabeca[eixoX] = TamX/2;//posicao da cabeça da cobra em X
    posicaocabeca[eixoY] = TamY/2;//posicao da cabeça da cobra em Y
    fruta[frutaX] = (rand() % TamX-2) + 1;
    fruta[frutaY] = (rand() % TamY-2) + 1;

    for ever{
        system("clear");
        printf("\t\t\tSNAKE GAME\n\n");
        if(fruta[frutaX] == posicaocabeca[eixoX] && fruta[frutaY] == posicaocabeca[eixoY]){
            fruta[frutaX] = (rand() % TamX-4)+2;
            fruta[frutaY] = (rand() % TamY-4)+2;
            BodySnakeSize++;
        }
        mostracampo(posicaocabeca,fruta,posicaocorpo,BodySnakeSize);
        printf("\n\nQuantidade de frutas pegas no total: %d",BodySnakeSize+1);
        //verifica se esta chegando algo do teclado
        usleep(100000);
        if(kbhit())
            controle = getchch();//se estiver ele atribui para controle
        setbuf(stdin,NULL);

        if(controle == cima || controle == baixo || controle == direita || controle == esquerda) 
            flag = controle;//se controle for iguala  qualquer direcao flag é mudado
        else controle = flag;//se não controle recebera flag, que tem a ultima direcao 

        //Bloco que controla se a cobra não passou por cima dela mesma, ou ultrapassou o limite do mapa
        if( posicaocabeca[eixoY] == TamY-1 ) break;
        if( posicaocabeca[eixoX] == TamX-1 ) break;
        if( posicaocabeca[eixoY] == 0 ) break;
        if( posicaocabeca[eixoX] == 0 ) break;
        if(conferecorpo(posicaocorpo,BodySnakeSize)) break;

        flagcabeca[eixoX] = posicaocabeca[eixoX];
        flagcabeca[eixoY] = posicaocabeca[eixoY];

        //bloco de if else para movimentar a cabeça da cobra
        if(controle == cima ) posicaocabeca[eixoY]--;
        else if(controle == baixo ) posicaocabeca[eixoY]++;
        else if(controle == direita ) posicaocabeca[eixoX]++;
        else if(controle == esquerda ) posicaocabeca[eixoX]--;
        //Bloco que controla o corpo da cobra
        switch (BodySnakeSize){
        case -1:
            break;
        case 0: 
            posicaocorpo[eixoX][BodySnakeSize] = flagcabeca[eixoX];
            posicaocorpo[eixoY][BodySnakeSize] = flagcabeca[eixoY];
        default:
            for(int j=BodySnakeSize;j>0;j--){
                posicaocorpo[eixoX][j] = posicaocorpo[eixoX][j-1];
                posicaocorpo[eixoY][j] = posicaocorpo[eixoY][j-1];
            }
            posicaocorpo[eixoX][0] = flagcabeca[eixoX];
            posicaocorpo[eixoY][0] = flagcabeca[eixoY];
        }
        
    }
    system("clear");
    printf("Voce perdeu.\n\n");
    printf("Sua pontuacao foi de : %d\n\n",BodySnakeSize+1);
    getchar();
    return 0;
}