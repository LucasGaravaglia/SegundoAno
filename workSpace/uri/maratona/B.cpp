#include <stdio.h>

int main(){
    int n;
    int carlos,resto;
    int flag=0;
    int i;
    scanf("%d",&n);
    scanf("%d",&carlos);
    for(i=1;i<n;i++){
        scanf("%d",&resto);
        if(resto > carlos){
            flag = 1;
        }
    }
    if(flag){
        printf("N\n");
    }else{
        printf("S\n");
    }


    return 0;
}