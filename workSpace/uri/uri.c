#include <stdio.h>
#include <math.h>
#include <string.h>


int endfile(char *s){
    if(strlen(s) && s[0] == '*') return 0;
    return 1;
}

int convert(int x){
    switch (x){
        case 14: return 12;
        case 15: return 11;
        case 16: return 10;
        case 17: return 9;
        case 18: return 8;
        case 19: return 7;
        case 20: return 6;
        case 21: return 5;
        case 22: return 4;
        case 23: return 3;
        case 24: return 2;
        case 25: return 1;
        default:
            return x;
    }
}
int confere(char c,int *s){
    if(s[c-48] == 1) return 0;
    s[c-48] = 1;
    return 1;
}
void resetvet(int *s){
    for(i = 0;i<25;i++)
        s[i] = 0;
}
int main(){
    char vet[1000];
    int i;
    int movimentos;
    int s[25];
    scanf("%s",&vet);
    FILE *f = fopen("saida.txt","w");
    while(endfile(vet)){
        resetvet(s);
        movimentos = 0;
        movimentos += convert(abs('a' - vet[0]))*confere(vet[i],s);
        for(i = 1;vet[i];i++){
            if(vet[i] == vet[i-2]) movimentos += 0;
            else
                movimentos += convert(abs(vet[i-1] - vet[i]))*confere(vet[i],s);
        }
        printf("%d\n",movimentos);
        fprintf(f,"%d\n",movimentos);
        scanf("%s",&vet);
    }
    fclose(f);
    return 0;
}