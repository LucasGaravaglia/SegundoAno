#include "campo.h"

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

int kbhit(void){
    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if(ch != EOF)
    {
      ungetc(ch, stdin);
      return 1;
    }
    
    return 0;
}
 
int getchch(void){
    struct termios newtios, oldtios;
    int ch;

    tcgetattr(STDIN_FILENO, &oldtios);

    /* Reusa o modo atual. */
    newtios = oldtios;

    /* Desabilita o modo canônico e o echo */
    newtios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newtios);

    ch = getchar();

    /* Retorna o terminal ao normal. */
    tcsetattr(STDIN_FILENO, TCSANOW, &oldtios);

    return ch;
    }

void moldura(int j, int i,int fruta[]){
    if(i == fruta[frutaY] && j == fruta[frutaX]) printf(figurafruta);
    else if(i == 0 && j == 0) printf(QuinaEsqcima);
    else if(i == TamY-1 && j == 0) printf(QuinaEsqbaixo);
    else if(i == 0 && j == TamX-1) printf(QuinaDircima);
    else if(i == TamY-1 && j == TamX-1) printf(QuinaDirbaixo);
    else if(i == 0) printf(Retahorizontal);
    else if(i == TamY-1) printf(Retahorizontal);
    else if(j == 0 ) printf(RetaVertical);
    else if(j == TamX-1) printf(RetaVertical);
    else printf(" ");
}

int ocupado(int posicaocabeca[],int posicaocorpo[][1000],int BodySnakeSize, int i, int j){
    if(j == posicaocabeca[eixoX] && i == posicaocabeca[eixoY]) return 1;
    for(int k=0;k<=BodySnakeSize;k++)
        if(j == posicaocorpo[eixoX][k] && i == posicaocorpo[eixoY][k]) return 1;
    return 0;
}

int conferecorpo(int posicaocorpo[][1000],int BodySnakeSize){
    for(int i=0;i<BodySnakeSize+1;i++){
        for(int j=i+1;j<BodySnakeSize+1;j++){
            if(posicaocorpo[eixoX][i] == posicaocorpo[eixoX][j] && posicaocorpo[eixoY][i] == posicaocorpo[eixoY][j]) return 1;
        }
    }
    return 0;
}


void mostracampo(int posicaocabeca[],int fruta[],int posicaocorpo[][1000], int BodySnakeSize){
    int n = 254;
    for(int i=0;i<TamY;i++){
        for(int j=0;j<TamX;j++)
            if(ocupado(posicaocabeca,posicaocorpo,BodySnakeSize,i,j))
                printf(cheio);
            else moldura(j,i,fruta);
        printf("\n");        
        }

}
