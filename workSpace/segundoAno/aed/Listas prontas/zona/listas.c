#include <stdio.h>
#include <stdlib.h>

typedef int TipoIten;
typedef struct no{
	TipoIten info;
	struct no * prox;
}Lista;

int main(){

Lista *novo;
Lista *proximo;
Lista *aux;
int pass;

novo = (Lista *)malloc(sizeof(Lista));
if(novo == NULL) printf("ERRO\n");
proximo = novo;

while(1){
	printf("Degite um valor:\n");
	scanf("%d",&proximo->info);
	printf("Deseja continuar ? <1> sim <qualquer valor> nao \n");
	scanf("%d",&pass);
	if(pass == 1){
		proximo->prox = (Lista *)malloc(sizeof(Lista));
		proximo = proximo->prox;
	}
	else 
		break;
}
	system("clear");
	proximo->prox=NULL;
	proximo = novo;
	while(proximo != NULL){
		printf("Seu valor: %d\n",proximo->info);
		proximo = proximo->prox;
	}
printf("Qual valor deseja excluir?\n");
scanf("%d",&pass);
	proximo->prox=NULL;
	proximo = novo;
	aux = novo;
	while(proximo != NULL && proximo->info != pass){
		aux = proximo;
		proximo = proximo->prox;
		}	
	if(proximo != NULL){
		if(proximo == novo)
			novo = novo->prox;
		else
			aux->prox = proximo->prox;
		free(proximo);
	}else 
		 printf("Valor inexistente\n");


	system("clear");
	proximo->prox=NULL;
	proximo = novo;
	while(proximo != NULL){
		printf("Seu valor: %d\n",proximo->info);
		proximo = proximo->prox;
	}
	
}