//Aluno: Lucas Garavaglia
#include <stdio.h>

int vet[100];
char string[100];
int v[100];
int u[100];
int n;
int x;
char dst[100], src[100];


void exer1(){
    asm(".intel_syntax noprefix         \n\
        mov eax, 1                      \n\
        mov edx, n                      \n\
        xor ebx, ebx                    \n\
    ini:                                \n\
        cmp edx, 0                      \n\
        je fim                          \n\
        imul eax, [ebx*4+vet]           \n\
        dec edx                         \n\
        inc ebx                         \n\
        jmp ini                         \n\
    fim:                                \n\
        mov n, eax                      \n\
        .att_syntax prefix \n");
}

void exer2(){
    asm(".intel_syntax noprefix         \n\
        xor eax, eax                    \n\
    ini2:                               \n\
        cmp [eax+string], 0             \n\
        je fim2                         \n\
        inc eax                         \n\
        jmp ini2                        \n\
    fim2:                               \n\
        mov n, eax                      \n\
        .att_syntax prefix \n");
}

void exer3(){
    asm(".intel_syntax noprefix \n\
        xor eax, eax            \n\
        mov ecx, n              \n\
        xor ebx, ebx            \n\
    ini3:                       \n\
        cmp ecx, 0              \n\
        jg fim3                 \n\
        add eax, [vet+4*ebx]    \n\
        inc ebx                 \n\
        dec ecx                 \n\
        jmp ini3                \n\
    fim3:                       \n\
        mov n, eax              \n\
    .att_syntax prefix \n")
}

void exer5(){
    asm(".intel_syntax noprefix \n\
        mov eax, n              \n\
        xor edx, edx            \n\
        xor ecx, ecx            \n\
    ini5:                       \n\
        cmp eax, 0              \n\
        je fim5                 \n\
        mov ebx,[vet+edx*4]     \n\
        imul ebx, ebx           \n\
        add ecx, ebx            \n\
        inc edx                 \n\
        dec eax                 \n\
        jmp ini5                \n\
    fim5:                       \n\
        mov n, ecx              \n\
    .att_syntax prefix\n");
}

void exer6(){
    asm(".intel_syntax noprefix \n\
        xor eax, eax            \n\
        xor ecx, exc            \n\
        mov edx, n              \n\
    ini6:                       \n\
        cmp edx, o              \n\
        je fim6                 \n\
        shr [vet+ecx*4]         \n\
        jc continue             \n\
        inc eax                 \n\
    continue:                   \n\
        dec edx                 \n\
        inc ecx                 \n\
        jmp ini6                \n\
    fim6:                       \n\
    mov n, eax                  \n\
    .att_syntax prefix\n");
}

void exer7(){
    asm(".intel_syntax noprefix \n\
        xor eax, eax            \n\
        xor ecx, exc            \n\
        mov edx, n              \n\
    ini7:                       \n\
        cmp edx, o              \n\
        je fim7                 \n\
        sal [vet+ecx*4]         \n\
        jc continue             \n\
        inc eax                 \n\
    continue7:                  \n\
        dec edx                 \n\
        inc ecx                 \n\
        jmp ini7                \n\
    fim7:                       \n\
    mov n, eax                  \n\
    .att_syntax prefix\n");
}

void exer8(){
    asm(".intel_syntax noprefix \n\
        xor eax, eax            \n\
        mov ebx, n              \n\
        mov ecx, x              \n\
        xor edx, edx            \n\
    ini8:                       \n\
        cmp ebx, 0              \n\
        je fim8                 \n\
        cmp ecx, [vet+eax*4]    \n\
        je conta8               \n\
        inc eax                 \n\
        dec ebx                 \n\
    conta8:                     \n\
        lea edx, vet+eax*4      \n\
    fim8:                       \n\
        mov n, edx              \n\
    .att_syntax prefix\n");
}

void exer9(){
    asm(".intel_syntax noprefix \n\
        mov eax, 1              \n\
        mov ebx, [vet]          \n\
        mov edx, n              \n\
    ini9:                       \n\
        cmp edx, 0              \n\
        je fim9                 \n\
        cmp ebx, [vet+eax*4]    \n\
        jb conta9               \n\
    continue9:                  \n\
        inc eax                 \n\
        dec edx                 \n\
        jmp ini9                \n\
    conta9:                     \n\
        mov ebx, [vet+eax*4]    \n\
        jmp continue9           \n\
    fim9:                       \n\
        mov n, ebx              \n\
    .att_syntax prefix\n");
}

void exer10(){
    asm(".intel_syntax noprefix \n\
        xor edx, edx            \n\
        xor eax, eax            \n\
        xor ebp, ebp            \n\
        mov ebx, n              \n\
    ini10:                      \n\
        cmp ebx, 0              \n\
        je fim10                \n\
        mov ecx, [v+eax*4]      \n\
        imul ecx, [u+eax*4]     \n\
        add edx, ecx            \n\
        inc eax                 \n\
        dec ebx                 \n\
        jmp ini10               \n\
    fim10:                      \n\
        mov n, edx              \n\
    .att_syntax prefix\n");
}

void exer11(){
    asm(".intel_syntax noprefix \n\
        xor eax, eax            \n\
        mov ebx, x              \n\
        mov ecx, 0              \n\
    ini11:                      \n\
        cmp ebx, 0              \n\
        je fim11                \n\
        sal ebx                 \n\
        adc eax, ecx            \n\
        jmp ini11               \n\
    fim11:                      \n\
        mov n, eax              \n\
    .att_syntax prefix\n");
}

void exer12(){
    asm(".intel_syntax noprefix \n\
        mov eax, n              \n\
        xor ebx, ebx            \n\
    ini12:                      \n\
        cmp eax, 0              \n\
        je fim12                \n\
        mov edx, 0              \n\
        idiv 10                 \n\
        inc ebx                 \n\
        jmp ini12               \n\
    fim12:                      \n\
        mov n, ebx              \n\
    .att_syntax prefix\n");
}

void exer13(){
    asm(".intel_syntax noprefix \n\
        mov eax, n              \n\
        xor ebx, ebx            \n\
    ini13:                      \n\
        cmp eax, 0              \n\
        je fim13                \n\
        mov edx, 0              \n\
        idiv 10                 \n\
        add ebx,edx             \n\
        jmp ini13               \n\
    fim13:                      \n\
        mov n, ebx              \n\
    .att_syntax prefix\n");
}

void exer14(){
    asm(".intel_syntax noprefix \n\
        mov eax, n              \n\
        xor ebx, ebx            \n\
    ini14:                      \n\
        cmp eax, 0              \n\
        je fim14                \n\
        mov edx, 0              \n\
        idiv 10                 \n\
        mov ecx, edx            \n\
        imul edx, ecx           \n\
        add ebx,edx             \n\
        jmp ini14               \n\
    fim14:                      \n\
        mov n, ebx              \n\
    .att_syntax prefix\n");
}

void exer15(){
    asm(".intel_syntax noprefix \n\
        xor eax, eax            \n\
        xor ebx, ebx            \n\
    ini15:                      \n\
        cmp byte ptr[src+eax], 0\n\
        je fim15                \n\
        mov ebx, [src+eax]      \n\
        mov [dst+eax], ebx      \n\
        jmp ini15               \n\
    fim15:                      \n\
    .att_syntax prefix\n");
}

int main(){

    return 0;
}
