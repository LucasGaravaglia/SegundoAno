#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Exercicio 5:
Mais estáveis:
	Todos exeto buble sort
Exercicio 6:
*/

typedef struct no{
	int info;
	struct no *prox;	
}Lista;

Lista* inserecab(Lista *l, int info){
	Lista* aux;
	aux = malloc(sizeof(Lista));
	aux->info = info;
	aux->prox = l;
	return l;
}

Lista* removevalor(Lista *l, int info){
	Lista *aux = l;
	Lista *ant;
	if(l->info == info){
	l = l->prox;
	free(aux);
	}else{
		while(aux != NULL || aux->info != info){
			ant = aux;
			aux = aux->prox;
		}
	if(aux == NULL) printf("Valor não encontrado\n");
		else{
			ant->prox = aux->prox;
			free(aux);
		} 
	return l;
	}
}
int procuramaior(Lista*l){
	int temp = 0;
	while(l)
		if(l->info > temp) temp = l->info;
	return temp;
}

Lista* OrdenaLista(Lista* l){
	Lista *newlist = NULL;
	int temp=0;
	while(l){
		temp = procuramaior(l);
		newlist = inserecab(newlist,temp);
		l = removevalor(l,temp);
	}
	return newlist;
}

int buscabinaria(int vet[], int n, int x){
	int exmenor,exmaior;
	int procura;
	int retorno = 0;
	exmenor = -1;
	exmaior = n;

	while(exmenor < exmaior-1){
		procura = (exmaior + exmenor) / 2;
		if(vet[procura] > x)
			exmaior = procura;
		else 
			exmenor = procura;
		retorno++;
	}
	if(procura == x-1) return -1;
	return retorno;
}

int funcaocomplexidadelog(int k, int n){
	int x;
	if(n == 1) return k;
	if(n%2 == 0){
		x = funcaocomplexidadelog(k,n/2);
		x = x*x;
	}else{
		x = funcaocomplexidadelog(k,n/2);
		x = x*x*k;
	}
	return x;
}
//Vetor a ser ordenado||Tamanho do vetor||menor valor||posição atual||Posição do menor valor
int scrmenor(int vetor[],int tamax, int menor,int atual,int temp){
	//se chegar na ultima posição do vetor retorna temp"
	if(tamax == atual) return temp;
	//Se atual for menor que a variavel menor
	if(vetor[atual] < menor){
		//Atualiza variavel temp"Posição menor valor"e o valor de menor
		menor = vetor[atual];
		temp = atual;
	}
	
	return scrmenor(vetor,tamax,menor,atual+1,temp);
}

void sortrecursivo(int vetor[],int tamax,int atual){
	int menor = vetor[atual];
	int at;
	int temp = atual;
	if(tamax != atual){
		temp = scrmenor(vetor,tamax,menor,atual,temp);
		//Troca o elemento atual com o menor do vetor
		at = vetor[atual];
		vetor[atual] = vetor[temp];
		vetor[temp] = at;
		//------------------------------------------
		sortrecursivo(vetor,tamax,atual+1);//chama a funcao dnv, com a proxima posição do vetor
	}
}
void ExercicioRecursividadeListaBucOrde(){
	int vetor[50];
	system("clear");
	for(int i = 0;i<15;i++)
		scanf("%d",&vetor[i]);
	sortrecursivo(vetor,15,0);
	for(int i = 0;i<15;i++)
		printf("%d ",vetor[i]);
}




// int main(){

// return 0;
// }
