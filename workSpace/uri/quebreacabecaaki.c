// #include <stdio.h>
// #include <math.h>

// int DemandaPosto[200000];
// int npostos, nrefinarias, npares;
// int Estoque[200000];
// int pares[200000][3];

// int auxDem[200000];
// int auxEst[200000];
// int auxNpostos, auxNref, auxNpares;
// int auxPares[200000][3];
// int time = 9999;

// int temEstoque(int refinaria){
//     int ref = auxPares[refinaria][1] - 1;
//     if(auxEst[ref]>0)return 1;
//     return 0;
// }

// int menor(int a, int b){
//     if(a < b)return a;
//     return b;
// }
// int maior(int a, int b){
//     if(a > b)return a;
//     return b;
// }
// int desconta(int id){
//     int posto, ref;
//     posto = auxPares[id][0] - 1;
//     ref = auxPares[id][1] - 1;
//     if(auxDem[posto] > auxEst[ref]){
//         auxDem[posto] =  auxDem[posto] - auxEst[ref];
//         auxEst[ref] = 0;
//         return 0;
//     }else if(auxDem[posto] < auxEst[ref]){
//         auxEst[ref] = auxEst[ref] - auxDem[posto];
//         auxDem[posto] = 0;
//         return 1;
//     }else{
//         auxDem[posto] = auxEst[ref] = 0;
//         return 1;
//     }
// }

// int satisfaz(int posto){
//     int i, menorTempo = 9999, idmenor = -1, tempoTotal = -1;
//     int aux;
//     while(auxDem[posto] > 0){
//         menorTempo = 9999;
//         idmenor = -1;
//         for(i = 0;i < npares;i++){
//             if((posto + 1) == auxPares[i][0] && auxPares[i][2] < menorTempo){
//                 menorTempo = auxPares[i][2];
//                 idmenor = i;
//             }
//         }
//         if(idmenor != -1 && menorTempo != 9999){
//             if(temEstoque(idmenor))
//                 desconta(idmenor);
//             else{
//                 auxPares[idmenor][0] = -10;
//             }
//             tempoTotal = maior(tempoTotal, menorTempo);
//             auxPares[idmenor][2] = 9999;
//         }else return 9999;

//     }


//     return tempoTotal;

// }
// void copiavetor(int a[], int n, int b[]){
//     for(int i = 0;i<n;i++){
//         a[i] = b[i];
//     }
// }

// void copiamatriz(int a[][3], int n, int b[][3]){
//     for(int i = 0;i<n;i++){
//         a[i][0] = b[i][0];
//         a[i][1] = b[i][1];
//         a[i][2] = b[i][2];
//     }
// }

// void troca_char(int str[], int p1, int p2){
//   int tmp;
//   tmp = str[p1];
//   str[p1] = str[p2];
//   str[p2] = tmp;
// }

// void permutacao_recursiva(int str[], int k){
//   int i, len;
//   int j, tempototal = -1, aux = 0;
//   len = npostos;

//   if (k == len){
//       copiavetor(auxDem, npostos,  DemandaPosto);
//       copiavetor(auxEst, nrefinarias, Estoque);
//       copiamatriz(auxPares, npares , pares);

//       for(i=0;i<npostos;i++){
//           aux = satisfaz(str[i]);
//           tempototal = maior(tempototal, aux);
//       }
//       time = menor(time, tempototal);

//   }
//   else{
//     for (i = k; i < len; i++){
//       troca_char(str, k, i);
//       permutacao_recursiva(str, k + 1);
//       troca_char(str, i, k);
//     }
//   }
// }

// void lista_permutacoes(int vet[]){
//     permutacao_recursiva(vet, 0);
// }
// int main (){
//     int i;
//     int tempototal = -1;
//     int tempototal2 = -1;
//     int aux = 0;

//     scanf("%d %d %d",&npostos,&nrefinarias,&npares);
//     for(i=0;i<npostos;i++)
//         scanf("%d",&DemandaPosto[i]);
//     for(i=0;i<nrefinarias;i++)
//         scanf("%d",&Estoque[i]);
//     for(i=0;i<npares;i++)
//         scanf("%d %d %d",&pares[i][0],&pares[i][1],&pares[i][2]);

//     int possiveis[npostos];
//     for(i = 0;i< npostos;i++)
//         possiveis[i] = i;

//     lista_permutacoes(possiveis);

//     if(time == 9999)
//         printf("-1\n");
//     else
//         printf("%d\n", time);
//     return 0;

// }