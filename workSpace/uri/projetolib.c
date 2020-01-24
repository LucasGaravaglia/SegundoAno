// #include <stdio.h>
// #define linha 10
// #define coluna 50
// int main(){
//     printf("\u2554");

// for(int i=0;i<coluna;i++)
//     printf("\u2550");
// printf("\u2557");
// printf("\n");

// for(int i=0;i<linha;i++){
// printf("\u2551");
//     for(int j=0;j<coluna;j++)
//     printf(" ");
// printf("\u2551");
// printf("\n");
// }

// printf("\u255a");
// for(int i=0;i<coluna;i++)
//     printf("\u2550");
// printf("\u255d");
// }
// #include <stdio.h>
// #include <math.h>
//     int DemandaPosto[10000];
//     int npostos, nrefinarias, npares;
//     int Estoque[10000];
//     int pares[10000][3];
// int main (){
//     int idmenor = -1;
//     int tempototal = 0;
//     int menortempo = 0;
//     int idpares;
//     scanf("%d%d%d",&npostos,&nrefinarias,&npares);
//     for(int i=0;i<npostos;i++)
//         scanf("%d",&DemandaPosto[i]);
//     for(int i=0;i<nrefinarias;i++)
//         scanf("%d",&Estoque[i]);
//     for(int i=0;i<npares;i++)
//         scanf("%d%d%d",&pares[i][0],&pares[i][1],&pares[i][2]);

//     for(int i=0;i<npostos;i++)
//         while(DemandaPosto[i] > 0){
//             idpares = -1;
//             menortempo = 999999;
//             for(int j=0;j<npares && pares[j][0] <= j+1;j++){
//                 if(pares[j][0] == i && pares[j][1] <= menortempo){
//                     menortempo = pares[j][2];
//                     idmenor = j;
//                 }
//             }
//             if(idpares != -1){

//             }
            
//         }
    
//     return 0;
    
// }