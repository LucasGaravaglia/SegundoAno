#include <stdio.h>
#include <stdlib.h>
//Aluno: Lucas Garavaglia
void shiftmaior(int v*, int a, int b){
    asm(".intel_syntax noprefix \n\
    mov esi,[ebp+8]             \n\
    mov ecx,[ebp+12]            \n\
    1:  cmp ecx,[ebp+16]        \n\
        jge 3f                  \n\
        mov eax,[esi]           \n\
        cmp eax, [esi+4]        \n\
        jle 2f                  \n\
        xchg eax,[esi+4]        \n\
        xchg eax,[esi]          \n\
    2:  inc ecx                 \n\
        lea esi,[esi+4]         \n\
        jmp 1b                  \n\
    3:                          \n\
    .att_syntax prefix");
}
void ordenar(int *v, int n){
    asm(".intel_syntax noprefix \n\
    mov ecx [ebp+12]            \n\
    dec ecx                     \n\
    10: jeccxz 20               \n\
        push ecx                \n\
        sub esp, 12             \n\
        mov [esp+8],ecx         \n\
        mov DWORD PTR [esp+4],0 \n\
        mov eax,[ebp+8]         \n\
        mov [esp],eax           \n\
        call shiftmaior         \n\
        add esp,12              \n\
        pop ecx                 \n\
        dec ecx                 \n\
        jmp10                   \n\
    20:                         \n\
    .att_syntax prefix");
}
void showvet(int *v, int n){
    int i;
    for(i = 0;i<n;i++)
        printf("#%d = %d\n",i,v[i]);
}
int v[10] = {10, 9, 8, 7, 6, 1, 2, 3, 4, 5},n = 10;
int main(){
    asm(".intel_syntax noprefix     \n\
        sub esp, 8                  \n\
        mov eax, n                  \n\
        mov [esp+4],eax             \n\
        mov eax, v                  \n\
        mov [esp], eax              \n\
        call ordenar                \n\
        add esp, 8                  \n\
    .att_syntax prefix");
}