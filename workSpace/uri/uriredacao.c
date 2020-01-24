#include <stdio.h>
#include <string.h>

int main(){
    char a[40],b[40],c[40];
    scanf("%s",&a);
    scanf("%s",&b);
    scanf("%s",&c);
    if(  strcmp(a,"vertebrado") && strcmp(b,"ave") && strcmp(c,"carnivoro")  ){
        printf("aguia\n");
    }else if(  strcmp(a,"vertebrado") && strcmp(b,"ave") && strcmp(c,"onivoro")  ){
        printf("pomba\n");
    }else if(  strcmp(a,"vertebrado") && strcmp(b,"mamifero") && strcmp(c,"onivoro")  ){
        printf("homem\n");
    }else if(  strcmp(a,"vertebrado") && strcmp(b,"mamifero") && strcmp(c,"herbivoro")  ){
        printf("vaca\n");
    }else if(  strcmp(a,"invertebrado") && strcmp(b,"inseto") && strcmp(c,"hematofago")  ){
        printf("pulga\n");
    }else if(  strcmp(a,"invertebrado") && strcmp(b,"inseto") && strcmp(c,"herbivoro")  ){
        printf("lagarta\n");
    }else if(  strcmp(a,"invertebrado") && strcmp(b,"anelideo") && strcmp(c,"hematofago")  ){
        printf("sanguessuga\n");
    }else{
        printf("minhoca\n");
    }
    return 0;
}