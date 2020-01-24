#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b){
    return a+b;
}

int f1(){ }
int f2(){ }
int f3(){ return -1; }
int f4(){ return -2; }

int lenght(char *s){
    int i;
    for(i = 0;*s;s++) i++;
    return i;
}

int fatorial(int n){
    if (n >0) return n* fatorial(n-1);
    else return 1;
}

void dump(unsigned char *p,unsigned char *q,int width){
    int i;
        for(i = width+1;p <= q;i++,p++){
            if( i > width) {
                i=0;
                printf("\n");
                printf("%p: ",p);
            }
            printf("%02X ",*p);
        }
        printf("\n");
}

int z = -1;

int main(int argc,char *argv[]){
    char s[] = "abAB01 \n";
    float x = -255.2;
    float y = -x;
    // dump((unsigned char *)&fatorial,(unsigned char *)&dump-1,10);
    dump(dump,main,10);
    // dump((unsigned char *)&f1 ,(unsigned char *)&f2-1 ,10);
    // printf("\n");
    // dump((unsigned char *)&f2 ,(unsigned char *)&f3-1 ,10);
    // printf("\n");
    // dump((unsigned char *)&f3 ,(unsigned char *)&f4-1 ,10);
    // printf("\n");
    // dump((unsigned char *)&f4 ,(unsigned char *)&lenght-1 ,10);
    // dump((unsigned char *)&lenght ,(unsigned char *)&dump-1 ,10);
    // dump((unsigned char *)&x ,(unsigned char *)&x +sizeof(float)-1 ,10);
    // dump((unsigned char *)&y ,(unsigned char *)&y +sizeof(float)-1 ,10);
    // dump((unsigned char *)&z ,(unsigned char *)&z +sizeof(int)-1 ,10);

    return 0;
}