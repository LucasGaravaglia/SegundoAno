#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>



int isanobissexto(int ano){
    return ((ano % 4 == 0) &&
            (ano %100 != 0)) ||
            (ano % 400==0);
}

int isdata(int mes,int ano){
    switch (mes){
        case 1:;
        case 3:;
        case 5:;
        case 7:;
        case 8:;
        case 10:;
        case 12: return 3;
        case 4:;
        case 6:;
        case 9:;
        case 11: return 2;
        case 2: return isanobissexto(ano);
    }
}

//tranforma a data em dias usando um ano base definido no começo do programa.
void transformardia(int *diaa,int mes,int ano, int DATA_BASE){
    int dia = *diaa;
    mes--;
    if(mes == 0) mes = 12;
    for(;ano>DATA_BASE;ano--){
        for(;mes>0;mes--){
            dia= dia + (28+isdata(mes,ano));
        }
        mes=12;
    }
    (*diaa) = dia;
}

int main(){
    int DATA_BASE = 1600;
    int diaI,mesI,anoI;
    int diaF,mesF,anoF;
    int diaT=0,mesT=1;
    int diaC;

    printf("Digite sua data de nascimento sendo ela dia mes ano:\n");
    scanf("%d %d %d",&diaI,&mesI,&anoI);
    if(anoI > 2000) DATA_BASE = DATA_BASE +(anoI - 2000);
    else if(anoI < 2000) DATA_BASE = DATA_BASE - (2000 - anoI);
    int anoT = DATA_BASE;
    printf("\nDigite sua data de hoje sendo ela dia mes ano:\n");
    scanf("%d %d %d",&diaF,&mesF,&anoF);
    system("clear");
    transformardia(&diaI,mesI,anoI,DATA_BASE);
    transformardia(&diaF,mesF,anoF,DATA_BASE);
    diaC=diaF-diaI;
    printf("Dias percorridos : %d\n",diaC);

    for(;diaC>31;anoT++){
        for(;mesT<=12 && diaC>31;mesT++){
            diaC = diaC - (28+isdata(mesT,anoT));
        }
       if(mesT == 13) mesT = 1;
    }
    switch (diaC){
        case 30:{
            if(mesT != 2){
                diaT = diaC;
            }else{
                diaT = diaC - (28+isanobissexto(anoT));
                mesT++;
            }
        }
        case 29:{
            if(mesT != 2){
                diaT = diaC;
            }else if(isanobissexto(anoT)){
                diaT = diaC;
            }else{
                diaT=1;
                mesT++;
            }
        }
    case 31:{
        if(mesT == 1 || mesT == 3 || mesT == 5 || mesT == 7 || mesT == 8 || mesT == 10 || mesT == 12){
            diaT = diaC;
        }else if(mesT == 4 || mesT == 6 || mesT == 9 || mesT == 11){
            diaT = 1;
            mesT++;
        }else if(mesT == 2){
            diaT = diaC - (28+isanobissexto(anoT));
            mesT++;
        }
    }
    default: diaT = diaC;
    }
       mesT--;

    anoT = anoT - DATA_BASE;
    printf("\n%d anos, %d meses, %d dias\n\n\n",anoT,mesT,diaT);

    return 0;
}
