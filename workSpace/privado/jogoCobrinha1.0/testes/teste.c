#include <stdio.h>
#include <unistd.h>


inline void gotoxy(int x, int y){
    putp(tparm(cursor_address, y, x));
}


int main(void){
    gotoxy(1,2);
    printf("Ola mundo\n");
}