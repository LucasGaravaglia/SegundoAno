#include <stdio.h>

int main(){
    int v,n,i;
    float pos=0;
    scanf("%d%d",&v,&n);
    pos = n*v*0.1;
    for(i=1;i<10;i++){
        if(pos*i > (int)(pos*i)){
            printf("%d ",(int)((pos*i) - ((float)pos*i - (int)(pos*i)))+1);
        }else{
            printf("%d ",(int)pos*i);
        }
    }
    return 0;
}