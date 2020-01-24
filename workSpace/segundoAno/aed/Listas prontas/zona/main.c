
//Lista duplamente encadeada

#include <stdio.h>
#include <stdlib.h>

typedef int TipoItem;
typedef struct no{
    TipoItem info;
    struct no * prox;
    struct no * ant;
}Lista;

//Começa uma lista cujos dois lados apontam para nulo.
Lista* NovaLista(Lista* l,TipoItem info){
    
    l->info = info;
    l->ant = NULL;
    l->prox = NULL;
    return l;
}
//Insere um elemento na cabeça.
Lista* insere(Lista* l,TipoItem info){
    Lista* aux = (Lista*) malloc(sizeof(Lista));
    l->ant = aux;
    aux->info = info;
    aux->prox = l; //encadeia com a cabeca da lista
    return aux;// retorna a nova cabeca
}

//Remove um elemento da lista, seja na cabeça ou no corpo.
Lista * retira(Lista* l,TipoItem info){
    Lista * ant = l;    // elemento anterior
    Lista * p = l;      // usado para encontrar o elemento
                        // a ser retirado
    while(p!= NULL && p->info != info) { // localiza o elemento
    ant = p;
    p = p->prox;
    }
    if(p != NULL){          // elemento encontrado
        if(p == l) {        // remoc~ao na cabeca
            l = l->prox;// atualiza a cabeca
            l->ant = NULL;
        }else{               // remocao no meio
            ant->prox = p->prox;
            p->prox->ant = ant;
        }
        free(p);            // libera o no do elemento removido
    }else
        printf("Elemento n~ao encontrado\n");
    return l;
}

void ShowLista(Lista *l){
    Lista *t;
    t=l;
    while(t != NULL){
        printf("%d\n",t->info);
        t = t->prox;
    }
}

int main(){
    Lista *novo;
    TipoItem n=1;
    printf("Qual o primeiro valor que deseja inserir?\n");
    scanf("%d",&n);
    novo = (Lista*) malloc(sizeof(Lista));
    novo = NovaLista(novo,n);
    printf("Qual valor deseja colocar na lsita ?\nCaso deseje parar, so digitar (-1)\n");
    scanf("%d",&n);
    while(n!=-1){
        novo = insere(novo,n);
        scanf("%d",&n);
    }
    system("cls");
    ShowLista(novo);
    printf("Qual valor deseja apagar?\n");
    scanf("%d",&n);
    system("cls");
    ShowLista(retira(novo,n));

    return 0;
}
