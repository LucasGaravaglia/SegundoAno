#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "campo.h"

long long int velocidadecobra = 100000;


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
    fruta[frutaX] = (rand() % TamX-3) + 2;
    fruta[frutaY] = (rand() % TamY-3) + 2;
    usleep(velocidadecobra);
    criacampo();
    for ever{
        if(fruta[frutaX] == posicaocabeca[eixoX] && fruta[frutaY] == posicaocabeca[eixoY]){
            fruta[frutaX] = (2+(rand() % TamX-4));
            fruta[frutaY] = (2+(rand() % TamY-4));
            BodySnakeSize++;
        }
        usleep(velocidadecobra);
        exibecobra(posicaocabeca,fruta,posicaocorpo,BodySnakeSize);
        gotoxy(1,TamY+1);
        printf("\ne +velcoidade\nq -velocidade\nf nova fruta");
        printf("w,a,s,d para se movimentar.\nTotal de frutas pegas: %d",BodySnakeSize+1);
        gotoxy(TamX+10,1);
        if(kbhit())
            controle = getchch();//se estiver ele atribui para controle
        setbuf(stdin,NULL);

        if(controle == cima || controle == baixo || controle == direita || controle == esquerda || controle == reset || controle == aumenta || controle == diminui)
            if(controle == reset){
                fruta[frutaX] = 2+(rand() % TamX-4);
                fruta[frutaY] = 2+(rand() % TamY-4);
                controle = flag;
                criacampo();
            }else if(controle == aumenta){
                controle = flag;
                velocidadecobra *=10;
            }else if(controle == diminui){
                controle = flag;
                velocidadecobra /=10;
            }else{
                flag = controle;//se controle for igual a  qualquer direcao flag é mudado
            }
        else controle = flag;//se não controle recebera flag, que tem a ultima direcao 

        //Bloco que controla se a cobra não passou por cima dela mesma, ou ultrapassou o limite do mapa
        if( posicaocabeca[eixoY] == TamY-1 ) break;
        if( posicaocabeca[eixoX] == TamX-1 ) break;
        if( posicaocabeca[eixoY] == 1 ) break;
        if( posicaocabeca[eixoX] == 1 ) break;
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
            gotoxy(flagcabeca[eixoX],flagcabeca[eixoY]);
            printf(" ");
            break;
        case 0:
            gotoxy(posicaocorpo[eixoX][BodySnakeSize],posicaocorpo[eixoY][BodySnakeSize]);
            printf(" ");
            posicaocorpo[eixoX][BodySnakeSize] = flagcabeca[eixoX];
            posicaocorpo[eixoY][BodySnakeSize] = flagcabeca[eixoY];
        default:
            gotoxy(posicaocorpo[eixoX][BodySnakeSize],posicaocorpo[eixoY][BodySnakeSize]);
            printf(" ");
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
    return 0;
}