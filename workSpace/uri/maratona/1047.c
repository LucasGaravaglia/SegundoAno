#include <stdio.h>


int mini;
int minf;
int temp;
int horaT,minT;

int main(){
    scanf("%d%d",&temp,&mini);
    mini+=(temp*60);
    scanf("%d%d",&temp,&minf);
    minf+=(temp*60);
    temp = minf - mini;
    horaT = temp / 60;
    minT = temp%60;
    if(hotaT < 0)
    if(temp == 0){
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)");    
    }if(temp > 0){
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)",horaT,minT);    
    }else{
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)",horaT+23,minT+60);
    }
}