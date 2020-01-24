#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ErroLat 17508
#define ErroLongi 23847
#define pi 3.14159265358979323846

//ALTERAR CAMINHO DOS ARQUIVOS.
#define STARTSCRIPT "./script.sh"
#define DESTINOCOORDS "coords.txt"
//-----------------------------------------------------------------------------------


//Le o arquivo criado pelo script
void lerarquivo(int* a, int* b){
    FILE *f;
    int head;
    f = fopen("entrada.txt","r");
    if(f == NULL){
        printf("ERRO\n");
    }else{
        fscanf(f,"%d",&head);
        *a = head;
        fscanf(f,"%d",&head);
        *b = head;
        fclose(f);
    }
}
//Reajusta as coordenadas.
void AdjustCoord(int *lat, int *longi){
    int n1=0;
    int n2=0;
    int head;
    head = *lat;
    while(head != 0){
        head /= 10;
        n1++;
    }
    head = *longi;
    while(head != 0){
        head /= 10;
        n2++;
    }
    n1 -=7;
    n2 -=7;
    for(int i=0;i<n1;i++,(*lat) /= 10)
    ;
    for(int i=0;i<n2;i++,(*longi) /= 10)
    ;
    (*lat) += ErroLat;
    (*longi) += ErroLongi;
}

int main(){
    FILE *f;
    int lat, longi;
    //Executa o script que le o gps.
    system(STARTSCRIPT);
    //Le o arquivo criado pelo script.
    lerarquivo(&lat, &longi);
    //Abre o arquivo que sera escrito as novas coordenadas.
    f = fopen(DESTINOCOORDS,"w");
    if(!(lat == -1 || longi == -1)){
        //Reajusta as coordenadas.
        AdjustCoord(&lat,&longi);
        fprintf(f,"%d %d\n",lat,longi);
    }else
        fprintf(f,"9999999 9999999");
    fclose(f);
    return 0;
}