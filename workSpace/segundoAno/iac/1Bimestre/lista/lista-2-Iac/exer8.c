#include <stdio.h>

// void troca(int *a, int *b){
//     int c;
//     c = a;
//     a = b;
//     b = c;
// }
// void shiftmaior(int *v, int a, int b){
//     int i;
//     for(i = a;i<b;i++){
//         if(v[i] > v[i+1]){
//             troca(&v[i],&v[i+1]);
//         }
//     }
// }
void shiftmaior(int *v, int a, int b){
    asm(".intel_syntax noprefix \n\
    mov esi,[ebp+8]             \n\
    mov ecx,[ebp+12]            \n\
1:  cmp ecx,[ebp+16]            \n\
    jge 3                       \n\
    mov eax,[esi]               \n\
    cmp eax, [esi+4]            \n\
    jle 2                       \n\
    xchg eax,[esi+4]            \n\
    xchg eax,[esi]              \n\
2:  inc ecx                     \n\
    lea esi,[esi+4]             \n\
    jmp 1                       \n\
3:                              \n\
    .att_syntax prefix");
}

//void ordenar(int *v,int n){
//    int i;
//    for(i=n;i>0;i--)
//        shiftmaior(v,0,i);
//}

void ordenar(int *v, int n){
    asm(".intel_syntax noprefix \n\
    mov ecx [ebp+12]            \n\
    dec ecx                     \n\
10: jeccxz 20                   \n\
    push ecx                    \n\
    sub esp, 12                 \n\
    mov [esp+8],ecx             \n\
    mov DWORD PTR [esp+4],0     \n\
    mov eax,[ebp+8]             \n\
    mov [esp],eax               \n\
    call shiftmaior             \n\
    add esp,12                  \n\
    pop ecx                     \n\
    dec ecx                     \n\
    jmp10                       \n\
20:                             \n\
    .att_syntax prefix");
}

void show(int *v, int n){
    int i;
    for(i = 0;i<n;i++)
        printf("#%d = %d\n",i,v[i]);
}

int v[10] = {10,9,8,7,6,1,2,3,4,5},n=10;
int main(){
    asm(".intel_syntax noprefix     \n\
        sub esp, 8                  \n\
        mov eax, n                  \n\
        mov [esp+4],eax             \n\
        mov eax, OFFSET v           \n\
        mov [esp], eax              \n\
        call ordenar                \n\
        add esp, 8                  \n\
    .att_syntax prefix");
    show(v,n);
}
// int main(){
//     int v[100000] = {10, 9, 8, 7 ,1 ,2 ,3 ,4 ,5 ,6};
//     int n = 10;
//     ordenar(v,n);
//     show(v,n);
//     return 0;
// }