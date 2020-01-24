#include <stdio.h>
#include <stdlib.h>


typedef struct no { // estrutura de nó para árvore binária
int info;
struct no* esq;
struct no* dir;
}arvore;


int vazia(arvore *r){
    return (r == NULL);
}

arvore* inserir(arvore *var,int info){
    if(vazia(var)){
        var = (arvore*)malloc(sizeof(arvore));
        var->info = info;
        var->esq = NULL;
        var->dir = NULL; 
    }
    if(var->info < info)
        var->dir = inserir(var->dir,info);
    if(var->info > info)
        var->esq = inserir(var->esq,info);
    return var;
}

int maximo(arvore *var){
    while(var->dir != NULL)
        var = var->dir;
    return var->info;
}

int minimo(arvore *var){
    while(var->esq != NULL)
        var = var->esq;
    return var->info;
}

int tamanhoarvore(arvore* var){  
}

arvore* removeelemento(arvore *var,int info){
    if(vazia(var)) return NULL;
    if(info > var->info)
        var->dir = removeelemento(var->dir,info);
    if(info < var->info)
        var->esq = removeelemento(var->esq,info);
    if(info == var->info){
        if(var->dir == NULL && var->esq == NULL){
            free(var);
            var = NULL;
        }else if(var->esq == NULL){
            var->info = minimo(var->dir);
            var->dir = removeelemento(var->dir,var->info);
        }else{
            var->info = maximo(var->esq);
            var->esq = removeelemento(var->esq,var->info);
        }
    } 
    return var; 
}

void inordem(arvore* var){
    if(!vazia(var)){
        inordem(var->esq);
        printf("%d ",var->info);
        inordem(var->dir);
    }
}

void preordem(arvore* var){
    if(!vazia(var)){
        printf("%d ",var->info);
        inordem(var->esq);
        inordem(var->dir);
    }
}

void posordem(arvore* var){
    if(!vazia(var)){
        inordem(var->esq);
        inordem(var->dir);
        printf("%d ",var->info);
    }
}

int altura (arvore *r) {
   if (vazia(r)) 
      return -1; // altura da árvore vazia
   else {
      int alturaesq = altura (r->esq);
      int alturadir = altura (r->dir);
      if (alturaesq < alturadir) return alturadir + 1;
      else return alturaesq + 1;
   }
}

int somaarvore(arvore *r){ 
    if(vazia(r)) return 0;
    return somaarvore(r->esq)+somaarvore(r->dir)+r->info;
}

//recebe a arvore, recebe qual nivel deseja printar, e recebe 0, que ira somando na recursao para saber o nivel
void printnivel(arvore *r, int nivel,int alturaarvore){
    if(!vazia(r)){
        if(alturaarvore == nivel)
            printf("%d ",r->info);
    printnivel(r->esq,nivel,alturaarvore+1);
    printnivel(r->dir,nivel,alturaarvore+1);
    }
}

int auxcheia(arvore *r,int h, int n){
    if(!vazia(r)){
        if(r->esq == NULL && r->dir == NULL){
            return (h == n);
        }else
            return(auxcheia(r->esq,h,n+1) && auxcheia(r->dir,h,n+1));
    }else return 1;
}

//retorna 1 caso foi cheia ou 0 caso contrario
int arvorecheia(arvore *r){
    int h=altura(r);
    return auxcheia(r,h,0);
}

int estbinaria(arvore *r){
    int var;
    if(!vazia(r)){
        if((r->esq == NULL && r->dir == NULL) || (r->esq != NULL && r->dir != NULL)) var=1;
        else var = 0;
        var*= estbinaria(r->esq);
        var*= estbinaria(r->dir);
        return var;
    }else return 1;
}

int CalcArvore(arvore *r){
    int conta = 0;
    if(!vazia(r)){
        switch (r->info){
        case 42:conta = CalcArvore(r->esq); 
                conta *= CalcArvore(r->dir);
        case 43:conta = CalcArvore(r->esq); 
                conta += CalcArvore(r->dir);
        case 45:conta = CalcArvore(r->esq); 
                conta -= CalcArvore(r->dir);
        case 47:conta = CalcArvore(r->esq); 
                conta /= CalcArvore(r->dir);
        default:
            return r->info;
        }
    }else return 0;
}

arvore* removearvore2(arvore *r, int info){
    if(vazia(r)) return NULL;
    if(info > r->info) r->dir = removearvore2(r->dir,info);
    if(info < r->info) r->esq = removearvore2(r->esq,info);
    if(info == r->info){
        if(r->dir == NULL && r->esq == NULL){
            free(r);
            return NULL;
        }else if(r->esq == NULL){
                r->info = minimo(r->dir);
                r->dir = removearvore2(r->dir,r->info);
            }else{
                r->info = maximo(r->esq);
                r->esq = removearvore2(r->esq,r->info);
            }
    }
    return r;
}

int main(){
    arvore *var = NULL;
    // int i=0;
    // int expresssao[30];
    // do{    
    //     scanf("%d",&expresssao[i]);
    //     i++;
    // }while(expresssao[i-1] != -1);
    // i=0;
    // while(expresssao[i++]!=-1)
    // switch (expresssao[i]){
    // case 42: printf("* ");
    // case 43: printf("+ ");
    // case 45: printf("- ");
    // case 47: printf("/ ");    
    // default:
    //     printf("%d ",expresssao[i]);

    // }
    var = inserir(var,25);
    var = inserir(var,11);
    var = inserir(var,9);
    var = inserir(var,33);
    var = inserir(var,17);
    var = inserir(var,5);
    var = inserir(var,45);
    var = inserir(var,50);
    var = inserir(var,27);
    var = inserir(var,30);
    var = inserir(var,22);
    var = inserir(var,12);
    var = inserir(var,8);
    var = inserir(var,10);
    var = inserir(var,44);
    printnivel(var,0,0);

}
// * 42
// + 43
// - 45
// / 47

// 3 43 5 42 14 45 9 47 2 -1