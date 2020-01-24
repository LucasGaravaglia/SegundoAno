#include "campo.h"

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>


void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}

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

void criacampo(){
    for(int i=1;i<TamX;i++){
        for(int j=1;j<TamY;j++){
            gotoxy(i,j);
            if(i == 1 && j == 1) printf(QuinaEsqcima);
            else if(i == TamX-1 && j == 1) printf(QuinaDircima);
            else if(i == 1 && j == TamY-1) printf(QuinaEsqbaixo);
            else if(i == TamX-1 && j == TamY-1) printf(QuinaDirbaixo);
            else if(i == 1) printf(RetaVertical);
            else if(j == TamY-1) printf(Retahorizontal);
            else if(j == 1 ) printf(Retahorizontal);
            else if(i == TamX-1) printf(RetaVertical);
            else printf(" ");
        }
    }
}

int conferecorpo(int posicaocorpo[][1000],int BodySnakeSize){
    for(int i=0;i<BodySnakeSize+1;i++){
        for(int j=i+1;j<BodySnakeSize+1;j++){
            if(posicaocorpo[eixoX][i] == posicaocorpo[eixoX][j] && posicaocorpo[eixoY][i] == posicaocorpo[eixoY][j]) return 1;
        }
    }
    return 0;
}

void exibecobra(int posicaocabeca[],int fruta[],int posicaocorpo[][1000], int BodySnakeSize){
    int n = 254;
    gotoxy(fruta[frutaX],fruta[frutaY]);
    printf(figurafruta);
    gotoxy(posicaocabeca[eixoX],posicaocabeca[eixoY]);
    printf(cheio);
    for(int i=BodySnakeSize;i>=0;i--){
        gotoxy(posicaocorpo[eixoX][i],posicaocorpo[eixoY][i]);
        printf(cheio);    
    }

}
