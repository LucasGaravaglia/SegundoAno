#include <stdio.h>

int salao[500][500];
int m,n,k;

int roubou(int atualm,int atualn){
    if(salao[atualm][atualn] == 1) return 0;
    if(atualm == m && atualn == n) return 1;
    if(atualm < m) return roubou(atualm+1,atualn);
    if(atualn < n) return roubou(atualm,atualn+1);
}

int main(){
    int am,an,s;
    int i,j,z;
    scanf("%d%d%d",&m,&n,&k);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            salao[i][j] = 0;
        }
    }
    for(z=0;z<k;z++){
        scanf("%d%d%d",&am,&an,&s);
        for(i=0;i<=s;i++){
            if(am - i > 0 && an - i > 0){
                salao[am][an] = 1;
                salao[am+i][an+i] = 1;
                salao[am+i][an] = 1;
                salao[am][an+i] = 1;
                salao[am-i][an-i] = 1;
                salao[am-i][an] = 1;
                salao[am][an-i] = 1;
                salao[am+i][an-i] = 1;
                salao[am-i][an+i] = 1;
            }
        }
    }
    if(roubou(0,0)){
        printf("S\n");
    }else{
        printf("N\n");
    }



    return 0;
}