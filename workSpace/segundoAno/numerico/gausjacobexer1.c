#include <stdio.h>
#include <math.h>
#include <termios.h>

#define ever (;;)

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

int i=1;
char iteracao;
double x1=0,Yy=0,z1=0,w1=0;
double tempx,tempy,tempz,tempw;
void GaussJacob(){
    tempx = (7+(2*Yy)-(3*z1)-(4*w1))/12;
    tempy = (8-(8*x1)+(3*z1)-w1)/15;
    tempz = (10-(6*x1)+(7*Yy)-w1)/(-20);
    tempw = (7-(3*x1))/4;
    x1 = tempx;
    Yy = tempy;
    z1 = tempz;
    w1 = tempw;
    printf("iteracao %02d : [%.6lf|%.6lf|%.6lf|%.6lf]\n",i++,x1,Yy,z1,w1); 
}

void GaussJacob2(){
    tempx = (4-Yy-z1-w1)/7;
    tempy = (1-x1-(3*z1)-(4*w1))/(-9);
    tempz = (2-x1-(10*Yy)+w1)/20;
    tempw = (3-(8*x1)+(7*Yy)-(2*z1))/16;
    x1 = tempx;
    Yy = tempy;
    z1 = tempz;
    w1 = tempw;
    printf("iteracao %02d : [%.6lf|%.6lf|%.6lf|%.6lf]\n",i++,x1,Yy,z1,w1); 
}

void GaussSidel(){
    x1 = (7+(2*Yy)-(3*z1)-(4*w1))/12;
    printf("iteracao %02d : [%.6lf|%.6lf|%.6lf|%.6lf]\n",i,x1,Yy,z1,w1); 
    iteracao = getchChar();
    Yy = (8-(8*x1)+(3*z1)-w1)/15;
    printf("iteracao %02d : [%.6lf|%.6lf|%.6lf|%.6lf]\n",i,x1,Yy,z1,w1); 
    iteracao = getchChar();
    z1 = (10-(6*x1)+(7*Yy)-w1)/(-20);
    printf("iteracao %02d : [%.6lf|%.6lf|%.6lf|%.6lf]\n",i,x1,Yy,z1,w1); 
    iteracao = getchChar();
    w1 = (7-(3*x1))/4;
    printf("iteracao %02d : [%.6lf|%.6lf|%.6lf|%.6lf]\n",i++,x1,Yy,z1,w1); 

}

void GaussSidel2(){
    x1 = (4-Yy-z1-w1)/7;
    // printf("iteracao %02d : [%.6lf|%.6lf|%.6lf|%.6lf]\n",i,x1,Yy,z1,w1); 
    // iteracao = getchChar();    
    Yy = (1-x1-(3*z1)-(4*w1))/(-9);
    // printf("iteracao %02d : [%.6lf|%.6lf|%.6lf|%.6lf]\n",i,x1,Yy,z1,w1); 
    // iteracao = getchChar();
    z1 = (2-x1-(10*Yy)+w1)/20;
    // printf("iteracao %02d : [%.6lf|%.6lf|%.6lf|%.6lf]\n",i,x1,Yy,z1,w1); 
    // iteracao = getchChar();
    w1 = (3-(8*x1)+(7*Yy)-(2*z1))/16;
    printf("iteracao %02d : [%.6lf|%.6lf|%.6lf|%.6lf]\n",i++,x1,Yy,z1,w1); 
}

/*
 * --         -- ---  -----
 * |12 -2  3  4| |x|   |7 |
 * |8  15 -3  1| |y| = |8 |
 * |6  -7 -20 1| |z|   |10|
 * |3   0  0  4| |w|   |7 |
 * --         -- ---   ----
*/
int main(){
    printf("            : [   X    |   Y    |    Z    |   W    ]\n");
    for ever {
        // GaussJacob2();
        GaussSidel2();
        iteracao = getchChar();
    }

}
