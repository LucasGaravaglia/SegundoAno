 #include <stdio.h>
#include <stdlib.h>
//Exercicio 2 da lista 1.
//Aluno: Lucas Garavaglia
int Asmstrlen(char *s){
    asm(".intel_syntax noprefix         \n\
        mov esi ,[ebp+8]                \n\
        cld                             \n\
        1:  lodsb                       \n\
            cmp al, 0                   \n\
            jne 1b                      \n\
        mov eax ,esi                    \n\
        sub eax, [ebp+8]                \n\
        dec eax                         \n\
    .att_syntax prefix");
}
int n;
char *Asmstrcpy(char *dest, const char *src){
        n = Asmstrlen(src);
        asm(".intel_syntax noprefix \n\
            mov edi, [ebp+8]        \n\
            mov esi, [ebp+12]       \n\
            mov ecx, n              \n\
            cld                     \n\
            repne movsb             \n\
            mov eax, [ebp+8]        \n\
        .att_syntax prefix");
}
int AsmIspalin(char *s){
    asm(".intel_syntax noprefix \n\
        mov esi, [ebp+8]        \n\
        mov edi, esi            \n\
        xor eax, eax            \n\
        cld                     \n\
        mov ecx, -1             \n\
        repne scasb             \n\
        lea edi, [edi-2]        \n\
        1:  cmp esi, edi        \n\
            jge 3f              \n\
            lodsb               \n\
            std                 \n\
            scasb               \n\
            cld                 \n\
            jne 2f              \n\
            jmp 1b              \n\
        2:  mov eax, 0          \n\
            jmp 4f              \n\
        3:  mov eax, 1          \n\
        4:                      \n\
    .att_syntax prefix");
}
int Asmstrtoint(char *s){
    asm(".intel_syntax noprefix \n\
        push ebx                \n\
        xor edx, edx            \n\
        mov esi,[ebp+8]         \n\
        cld                     \n\
        1:  lodsb               \n\
            or al, al           \n\
            jz 2f               \n\
            imul edx, 10        \n\
            movzx ebx, al       \n\
            add edx, ebx        \n\
            sub edx, '0'        \n\
            jmp 1b              \n\
        2: mov eax, edx         \n\
        pop ebx                 \n\
    .att_syntax prefix");
}
char *AsmStrend(char *s){
    asm(".intel_syntax noprexi          \n\
    push ebx                            \n\
    mov esi ,[ebp+8]                    \n\
        cld                             \n\
        1:  lodsb                       \n\
            cmp al, 0                   \n\
            jne 1b                      \n\
        mov eax ,esi                    \n\
        sub eax, [ebp+8]                \n\
        dec eax                         \n\
        add eax,[ebp+8]                 \n\
    pop ebx                             \n\
    .att_syntax prefix");
}
char *AsmStrrchr(char *s,char c){
    asm(".intel_syntax noprexi          \n\
    push ebx                            \n\
    mov esi, [ebp+8]                    \n\
    mov ebx, [ebp+12]                   \n\
    cld                                 \n\
    1:                                  \n\
        lodsb                           \n\
        cmp eax, ebx                    \n\
        je 2f                           \n\
        cmp eax, 0                      \n\
        jne 1b                          \n\
        jmp 3f                          \n\
    2:                                  \n\
        mov eax, [esi-1]                \n\
    3:                                  \n\
    pop ebx                             \n\
    .att_syntax prefix");
}
char *AsmStrchr(char *s,char c){
    asm(".intel_syntax noprexi          \n\
    push ebx                            \n\
    mov esi ,[ebp+8]                    \n\
        cld                             \n\
        1:  lodsb                       \n\
            cmp al, 0                   \n\
            jne 1b                      \n\
    mov ebx, [ebp+12]                   \n\
    stc                                 \n\
    mov ecx, [ebp+8]                    \n\
    1:                                  \n\
        lodsb                           \n\
        cmp eax, ebx                    \n\
        je 2f                           \n\
        cmp [eax], [ecx]                \n\
        jne 1b                          \n\
        jmp 3f                          \n\
    2:                                  \n\
        mov eax, [esi+1]                \n\
    3:                                  \n\
    pop ebx                             \n\
    .att_syntax prefix");
}
int AsmContaChar(char *s, int c){
    asm(".intel_syntax noprefix         \n\
        push ebx                        \n\
        xor ecx,ecx                     \n\
        mov esi, [ebp+8]                \n\
        mov ebx, [ebp+12]               \n\
        cld                             \n\
        1:                              \n\
            lodsb                       \n\
            cmp eax,0                   \n\
            je 2f                       \n\
            cmp eax,ebx                 \n\
            jne 1b                      \n\
            inc ecx                     \n\
            jmp 1b                      \n\
        2:                              \n\
            mov eax, ecx                \n\
        pop ebx                         \n\
    .att_syntax prefix");
}
char *Asmstrcat(char *dest, char *src){
    asm(".intel_syntax noprefix         \n\
        mov esi ,[ebp+8]                \n\
        cld                             \n\
        1:  lodsb                       \n\
            cmp al, 0                   \n\
            jne 1b                      \n\
        mov edi, esi                    \n\
        mov ecx, -1                     \n\
        cld                             \n\
        repne movsb                     \n\
        mov eax,[ebp+8]                 \n\
    .att_syntax prefix");
}
char sa[100], sb[100], *pa, *pb, *pc, *pd;
int ta,ca,cb;
int main(){
    // scanf("%[^\n]",sb);
    // pa = strend(sa);
    // pb = strcpy(sa,sb);
    // ta = strlen(sa);
    // pc = strchr(sa,'x');
    // pd = strrchr(sa, 'x');
    // ca = contachar(sa, 'x');
    // ca = ispalin(sa);
    return 0;
}

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