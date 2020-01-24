#include <stdio.h>
#include <stdlib.h>

#define uchar unsigned char

void bytes(uchar *v, int *n){
    asm(".intel_syntax noprefix \n\
        jmp 2f                  \n\
        1: push ebp             \n\
        2:                      \n\
        lea esi, 1b             \n\
        lea ecx, 2b             \n\
        sub ecx, esi            \n\
        mov ebx, [ebp+12]       \n\
        mov [ebx], ecx          \n\
        mov edi, [ebp+8]        \n\
        jecxz 4f                \n\
        3:  mov al,[esi]        \n\
            mov [edi],al        \n\
            inc edi             \n\
            inc esi             \n\
            loop 3b             \n\
        4:                      \n\
        .att_syntax prefix");
}


void show(uchar v[], int n){
    int i;
    printf("(%d)",n);
    for(i=0;i<n;i++)
        printf("%02X",v[i]);
}

int main(){
    uchar v[100];
    int n;

    bytes(v,&n);
    show(v,n);
}