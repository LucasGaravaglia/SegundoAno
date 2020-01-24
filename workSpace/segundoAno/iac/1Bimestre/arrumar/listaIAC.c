#include <stdio.h>

int v[100];
int n;
char s[200];
int ler(){
    printf("Digite 5 numeros:\n");
    for(int i=0;i<5;i++){
        scanf("%d",&v[i]);
    }
    return 5;
}

Exercicio 1 
void exer1(){
     asm(
        ".intel_syntax noprefix             \n\
        push ebx                            \n\
        mov ebx, dword ptr[ebp+8]           \n\
        mov eax, 1                          \n\
        mov edx, dword ptr[ebp+12]          \n\
        xor ecx, ecx                        \n\
        ini:                                \n\
            cmp ecx, edx                    \n\
            jge fim                         \n\
            imul eax,dword ptr [ebx+4*ecx]  \n\
            inc ecx                         \n\
            jmp ini                         \n\
        fim:                                \n\
        pop ebx                             \n\
        .att_syntax prefix                  \n"
    );
}


void exer2(){
    scanf("%[^\n]",s);
     asm(
        ".intel_syntax noprefix             \n\
        mov eax ,0                          \n\
        ini:                                \n\
            mov edx ,[s+eax]                \n\
            cmp edx, 0                      \n\
            je fim                          \n\
            inc eax                         \n\
            jmp ini                         \n\
        fim:                                \n\
            mov n ,eax                      \n\
        .att_syntax prefix                  \n"
    );
    printf("%d\n",n);
}

int main(){

}
