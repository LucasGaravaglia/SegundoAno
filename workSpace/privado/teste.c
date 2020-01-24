#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}


int main(){
    gotoxy(2,20);
    printf("Ola mundo");

    gotoxy(100,20);
    printf("Ola mundo");
    return 0;
}