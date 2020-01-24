#include <stdio.h>
#include <string.h>
#define O_ACCMODE 00000003
#define O_RDONLY  00000000
#define O_WRONLY  00000001
#define O_RDWR    00000002
#define O_CREATE  00000100

void criar(char *nome,int mode){
    asm(".intel_syntax noprefix \n\
        push ebx                \n\
        mov eax, 8              \n\
        mov ebx,[ebp+8]         \n\
        mov ecx,[ebp+12]        \n\
        int 0x80                \n\
        pop ebx                 \n\
    .att_syntax prefix");
}

void chmod(char *nome,int mode){
    asm(".intel_syntax noprefix \n\
        push ebx                \n\
        mov eax, 15             \n\
        mov ebx,[ebp+8]         \n\
        mov ecx,[ebp+12]        \n\
        int 0x80                \n\
        pop ebx                 \n\
    .att_syntax prefix");
}

int open(char *nome,int flag,int mode){
    asm(".intel_syntax noprefix \n\
        push ebx                \n\
        mov eax, 5              \n\
        mov ebx,[ebp+8]         \n\
        mov ecx,[ebp+12]        \n\
        mov edx,[ebp+16]        \n\
        int 0x80                \n\
        pop ebx                 \n\
    .att_syntax prefix");
}

void close(int file){
    asm(".intel_syntax noprefix \n\
        push ebx                \n\
        mov eax, 6              \n\
        mov ebx,[ebp+8]         \n\
        int 0x80                \n\
        pop ebx                 \n\
    .att_syntax prefix");
}

void read(int file,char *a,int size_t){
    asm(".intel_syntax noprefix \n\
        push ebx                \n\
        mov eax, 3              \n\
        mov ebx,[ebp+8]         \n\
        mov ecx,[ebp+12]        \n\
        mov edx,[ebp+16]        \n\
        int 0x80                \n\
        pop ebx                 \n\
    .att_syntax prefix");
}

void write(int file,char *a,int size_t){
    asm(".intel_syntax noprefix \n\
        push ebx                \n\
        mov eax, 4              \n\
        mov ebx,[ebp+8]         \n\
        mov ecx,[ebp+12]        \n\
        mov edx,[ebp+16]        \n\
        int 0x80                \n\
        pop ebx                 \n\
    .att_syntax prefix");
}

void rmdir(char *file){
    asm(".intel_syntax noprefix \n\
        push ebx                \n\
        mov eax, 40             \n\
        mov ebx,[ebp+8]         \n\
        int 0x80                \n\
        pop ebx                 \n\
    .att_syntax prefix");
}

void mkdir(char *file){
    asm(".intel_syntax noprefix \n\
        push ebx                \n\
        mov eax, 39             \n\
        mov ebx,[ebp+8]         \n\
        int 0x80                \n\
        pop ebx                 \n\
    .att_syntax prefix");
}

// void rename(char *olddir, char *newdir){
//     asm(".intel_syntax noprefix \n\
//         push ebx                \n\
//         mov eax, 38             \n\
//         mov ebx,[ebp+8]         \n\
//         mov ebx,[ebp+12]        \n\
//         int 0x80                \n\
//         pop ebx                 \n\
//     .att_syntax prefix");
// }

int n;
void cout(char *word){
    n = strlen(word);
    asm(".intel_syntax noprefix \n\
        push ebx                \n\
        mov eax, 4              \n\
        mov ebx,1               \n\
        mov ecx,[ebp+8]         \n\
        mov edx,n               \n\
        int 0x80                \n\
        pop ebx                 \n\
    .att_syntax prefix");
}

void cin(char *a,int size_t){
    asm(".intel_syntax noprefix \n\
        push ebx                \n\
        mov eax, 3              \n\
        mov ebx,1               \n\
        mov ecx,[ebp+8]        \n\
        mov edx,[ebp+12]        \n\
        int 0x80                \n\
        pop ebx                 \n\
    .att_syntax prefix");
}

void time(size_t *tloc){
    asm(".intel_syntax noprefix \n\
        mov eax, 13             \n\
        mov ebx,[ebp+8]         \n\
        int 0x80                \n\
    .att_syntax prefix");
}



char vet[120];
char teste[200];
size_t tloc;
int main(){
    int fd;
    scanf("%s",&vet);
    fd = open(vet,O_RDONLY,0777);
    read(fd,teste,200);
    close(fd);
    printf("%s",vet);

    return 0;
}