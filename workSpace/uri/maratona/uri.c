#include <stdio.h>


int vet[100010];
int tam;
int i,j;
int temp;
int flag=0;



int main(){
    scanf("%d",&tam);
    for(i=0;i<tam;i++){
        scanf("%d",&vet[i]);
    }
    for(i=0;i<tam;i++){
        temp = vet[i];
        for(j=i;j<tam;j++){
            if(vet[j] > temp){
                printf("%d ",vet[j]);
                flag++;
                break;
            }
        }
    }
    for(i=0;i<flag;i++){
        printf("* ");
    }
    printf("\n");

    return 0;
}