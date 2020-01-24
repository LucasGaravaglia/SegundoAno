#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"
#include "menu.h"
#include "arquivo.h"

/* Função que remove os espaços escedentes de uma string
 * Pré-condição:
 * Pós-condição: String Sem espaços excedentes
*/
void removeSpaces(char s[]){
	char *temp = NULL;
	char novo[200];
    novo[0] = NULL;
	temp = strtok(s," ");
	while(temp != NULL){
		strcat(novo,temp);
		temp = strtok(NULL," ");
		if(temp != NULL) strcat(novo," ");
	}
	strcpy(s,novo);
}
/* Função que procura um codigo no arquivo de arvore
 * Pré-condição: Arquivo aberto, e posição valida.
 * Pós-condição: Posição no arquivo do codigo.
*/
int procurar(FILE* arquivoinfo,int pos_atual, int info){
    int retorno;
    no* aux = LeNo(arquivoinfo,pos_atual);
    if(aux->info.codigo == info){ 
        retorno = pos_atual;
    }else{ 
        retorno = procurar(arquivoinfo,aux->prox,info);
    }
    free(aux);
    return retorno;
}
/* Altera quantidade de exemplares de um determinado livro
 * Pré-condição: Arquivo de lista aberto
 * Pós-condição: Num de exemplares alterado
*/
void AlterarExemplares(FILE *arquivoinfo,int info,int nexemplares){
    cabecalho *cab = LeCabecalho(arquivoinfo);
    int PosNo = procurar(arquivoinfo,cab->pos_cabeca,info);
    no *infolivro = LeNo(arquivoinfo,PosNo);
    infolivro->info.NumExemplares = nexemplares;
    EscreveNo(arquivoinfo,infolivro,PosNo);
    free(cab);
    free(infolivro);
}
/* Procura e printa um livro a partir de seu codigo
 * Pré-condição: Livro existente na lista, arquivo de lista aberto
 * Pós-condição: Nenhuma
*/
void Procura_printaLivro_Lista(FILE *arquivoinfo,int info){
    cabecalho *cab = LeCabecalho(arquivoinfo);
    int PosNo = procurar(arquivoinfo,cab->pos_cabeca,info);
    no *infolivro = LeNo(arquivoinfo,PosNo);
    printf("Codigo do livro: %d\n",infolivro->info.codigo);
    printf("Autor do livro: %s\n",infolivro->info.autor);
    printf("Titulo do livro: %s\n",infolivro->info.titulo);
    printf("Numero de exemplares: %d\n",infolivro->info.NumExemplares);
    free(cab);
    free(infolivro);
}
/* Busca um livro no arquivo de arvore
 * Pré-condição: arquivo aberto.
 * Pós-condição: true caso o livro exista e false caso contrario
*/
int BuscarLivroArvore(FILE *arquivo,int info,int pos){
    ArvoreArquivo temp;
    fseek(arquivo,pos*sizeof(ArvoreArquivo),SEEK_SET);
    int key = fread(&temp,sizeof(ArvoreArquivo),1,arquivo);
    if(key == 1 && temp.ocupado == 1){
        if(temp.codigo == info) return 1;
        if(temp.codigo > info) return BuscarLivroArvore(arquivo,info,pos*2);
        if(temp.codigo < info) return BuscarLivroArvore(arquivo,info,(pos*2)+1);
    }else return 0;
}
/* Insere um codigo no arquivo de arvore
 * Pré-condição: Arquivo aberto
 * Pós-condição: Arquivo inserido
*/
void InsereCodigoArquivoBin(ArvoreArquivo r,FILE *arquivo,int pos){
    ArvoreArquivo temp;
    fseek(arquivo,pos*sizeof(ArvoreArquivo),SEEK_SET);
    int key = fread(&temp,sizeof(ArvoreArquivo),1,arquivo);
    if(key != 1 || temp.ocupado == 0){
        fseek(arquivo,pos*sizeof(ArvoreArquivo),SEEK_SET);
        fwrite(&r,sizeof(ArvoreArquivo),1,arquivo);
    }else{
        if(r.codigo < temp.codigo){
            InsereCodigoArquivoBin(r,arquivo,pos*2); 
        }else if(r.codigo > temp.codigo){
            InsereCodigoArquivoBin(r,arquivo,((pos*2)+1));
        }
    }
}
/* Retorna o menor codigo da arvore
 * Pré-condição: Arquivo aberto
 * Pós-condição: valor do menor codigo da arvore
*/
int mincodigo(FILE *arquivo,int pos){
    ArvoreArquivo atual;
    ArvoreArquivo prox;
    fseek(arquivo,pos*sizeof(ArvoreArquivo),SEEK_SET);
    fread(&atual,sizeof(ArvoreArquivo),1,arquivo);
    fseek(arquivo,(2*pos)*sizeof(ArvoreArquivo),SEEK_SET);
    int key = fread(&prox,sizeof(ArvoreArquivo),1,arquivo);
    if(key != 1 || prox.ocupado == 0) return atual.codigo;
    else return mincodigo(arquivo,(pos*2));    
}
/* Retorna o maior codigo da arvore
 * Pré-condição: Arquivo aberto
 * Pós-condição: Valor do maior codigo da arvore
*/
int maxcodigo(FILE *arquivo,int pos){
    ArvoreArquivo atual;
    ArvoreArquivo prox;
    fseek(arquivo,pos*sizeof(ArvoreArquivo),SEEK_SET);
    fread(&atual,sizeof(ArvoreArquivo),1,arquivo);
    fseek(arquivo,(1+(2*pos))*sizeof(ArvoreArquivo),SEEK_SET);
    int key = fread(&prox,sizeof(ArvoreArquivo),1,arquivo);
    if(key == 0 || prox.ocupado == 0) return atual.codigo;
    else return maxcodigo(arquivo,(pos*2)+1);    
}
/* Remove um codigo do arquivo de arvore
 * Pré-condição: Arquivo aberto
 * Pós-condição: True caso removido ou false caso contrario
*/
int RemoveCodigoArquivoBin(int info,FILE *arquivo,int pos){
    ArvoreArquivo esq;
    ArvoreArquivo dir;
    ArvoreArquivo temp;
    int key2;
    fseek(arquivo,pos*sizeof(ArvoreArquivo),SEEK_SET);
    int key = fread(&temp,sizeof(ArvoreArquivo),1,arquivo);
    if(key != 1 || temp.ocupado == 0)
        return 0;
    if(temp.codigo < info) return RemoveCodigoArquivoBin(info,arquivo,((pos*2)+1));
    if(temp.codigo > info) return RemoveCodigoArquivoBin(info,arquivo,pos*2);
    fseek(arquivo,(pos*2)*sizeof(ArvoreArquivo),SEEK_SET);
    key = fread(&esq,sizeof(ArvoreArquivo),1,arquivo);
    fseek(arquivo,(1+pos*2)*sizeof(ArvoreArquivo),SEEK_SET);
    key2 = fread(&dir,sizeof(ArvoreArquivo),1,arquivo);

    if((key != 1 || esq.ocupado == 0) && (key2 != 1 || dir.ocupado == 0)){
        temp.ocupado = 0;
        fseek(arquivo,pos*sizeof(ArvoreArquivo),SEEK_SET);
        fwrite(&temp,sizeof(ArvoreArquivo),1,arquivo);
        return 1;
    }else if(key == 0 || esq.ocupado == 0){
        temp.codigo = mincodigo(arquivo,((pos*2)+1));
        fseek(arquivo,pos*sizeof(ArvoreArquivo),SEEK_SET);
        fwrite(&temp,sizeof(ArvoreArquivo),1,arquivo);
        return RemoveCodigoArquivoBin(temp.codigo,arquivo,((pos*2)+1));
    }else{
        temp.codigo = maxcodigo(arquivo,pos*2);
        fseek(arquivo,pos*sizeof(ArvoreArquivo),SEEK_SET);
        fwrite(&temp,sizeof(ArvoreArquivo),1,arquivo);
        return RemoveCodigoArquivoBin(temp.codigo,arquivo,(pos*2));
    }
}
/* Le o cabeçalho do arquivo contendo as informaçoes da lista
 * Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
 * Pós-condição: retorna o ponteiro para o cabeçalho lido
*/
cabecalho* LeCabecalho(FILE * arq) {
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    fseek(arq,0,SEEK_SET); // posiciona no inı́cio do arquivo
    fread(cab,sizeof(cabecalho),1,arq);
    return cab;
}
/* Escreve no arquivo o cabeçalho contendo as informaçoes da lista
 * Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
 * Pós-condição: cabeçalho escrito no arquivo
*/
void EscreveCabecalho(FILE* arq, cabecalho* cab){
    fseek(arq,0,SEEK_SET); //posiciona no inı́cio do arquivo
    fwrite(cab,sizeof(cabecalho),1,arq);
}
/* le um nó em uma determinada posiçao do arquivo
 * Pré-condição: arquivo deve estar aberto e ser um arquivo de lista,pos deve ser uma posiçao válida da lista
 * Pós-condição: ponteiro para nó lido é retornado
*/
no* LeNo(FILE* arq, int pos) {
    no* x = malloc(sizeof(no));
    fseek(arq,sizeof(cabecalho)+ pos*sizeof(no),SEEK_SET);
    fread(x,sizeof(no),1,arq);
    return x;
}
/* Escreve um nó 
 * Pré-condição: Nenhuma
 * Pós-condição:em uma determinada posiçao do arquivo arquivo deve estar aberto e ser um arquivo de lista pos deve ser uma posiçao válida do arquivo nó escrito no arquivo
*/
void EscreveNo(FILE* arq, no* x, int pos){
    fseek(arq,sizeof(cabecalho)+ pos*sizeof(no),SEEK_SET);
    fwrite(x,sizeof(no),1,arq);
}
/* Insere um nó na lista
 * Pré-condição: arquivo aberto
 * Pós-condição: nó inserido
*/
void InsereLivroLista(FILE* arq, livro info){
    cabecalho* cab = LeCabecalho(arq);
    no x;
    x.info = info;
    x.prox = cab->pos_cabeca;
    if(cab->pos_livre == -1) { // nao há nós livres, entao usar o topo
        EscreveNo(arq,&x,cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }else { // usar nó da lista de livres
        no* aux = LeNo(arq,cab->pos_livre);
        EscreveNo(arq,&x,cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    EscreveCabecalho(arq,cab); free(cab);
}
/* Retira um nó da lista
 * Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
 * Pós-condição: nó retirado da lista caso pertença a ela
*/
void RetiraLivroLista(FILE* arq, int x){
    cabecalho* cab = LeCabecalho(arq);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;
    no* aux = NULL;
    while(pos_aux != -1 && ((aux = LeNo(arq,pos_aux))!= NULL) &&  aux->info.codigo != x  ){// procura o elemento a ser retirado
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if(pos_aux != -1) { //encontrou o elemento
        if(pos_ant == pos_aux){ // remoçao na cabeça
            cab->pos_cabeca = aux->prox;
        }else { // remoçao no meio
            no * ant = LeNo(arq,pos_ant);
            ant->prox = aux->prox;
            EscreveNo(arq,ant,pos_ant);
            free(ant);
        }
        aux->prox = cab->pos_livre; // torna o nó removido um nó livre
        cab->pos_livre = pos_aux;
        EscreveNo(arq,aux,pos_aux);
        EscreveCabecalho(arq,cab);
        free(aux);
    }
    free(cab);
}
/* Cria uma lista nova em arquivo
 * Pré-condiçao: arquivo aberto para leitura/escrita
 * Pós-condiçao: arquivo é inicializado com uma lista vazia
*/
void cria_lista_vazia(){
    FILE *arq = fopen("ArquivoBinarioInfo.bin","w+b");
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    cab->pos_cabeca = -1;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    EscreveCabecalho(arq,cab);
    free(cab);
    fclose(arq);
}
/* Imprime arvore com [,]
 * Pré-condição: arvore carregada para a memoria
 * Pós-condição: nenhuma
*/
void ImprimiArvoreBinaria(Arvore *r,int pos){
    if(pos == 1)printf("[");
    else printf(",[");
    if(r != NULL){
        printf("%d",r->info);
        ImprimiArvoreBinaria(r->esq,pos*2);
        ImprimiArvoreBinaria(r->dir,(pos*2)+1);
    }
    printf("]");
}
/* Insere um livro na lista em ordem crescente a partir do codigo
 * Pré-condição: nenhuma
 * Pós-condição: livro inserido ordenado 
*/
Lista* InsereListaOrdenado(Lista* l, livro info){
    Lista *aux;
    if(l == NULL){
        l = (Lista*)malloc(sizeof(Lista));
        l->info = info;
        l->prox = NULL;
        return l;
    }else if(l->info.codigo > info.codigo){
            aux = (Lista*)malloc(sizeof(Lista));
            aux->info = info;
            aux->prox = l;
            return aux;
        }else 
            l->prox = InsereListaOrdenado(l->prox,info);
    return l;
}
/* Função para apagar toda a lista de livro
 * Pré-condição: Nenhuma
 * Pós-condição: Lista limpa
*/
void DeleteLista(Lista* l){
    Lista *aux = l;
    Lista *ant;
    while(aux->prox){
        ant = aux;
        aux = aux->prox;
        free(ant);
    }
    free(aux);
}
/* Carrega todo o arquivo de lista para a memoria em ordem
 * Pré-condição: arquivo aberto
 * Pós-condição: uma lista de livros na memoria
*/
Lista* CarregaMemoriaLista(FILE *arquivo,int pos,Lista *r){
    no * nolista = LeNo(arquivo,pos);
    r = InsereListaOrdenado(r,nolista->info);
    if(nolista->prox != -1)
        r = CarregaMemoriaLista(arquivo,nolista->prox,r);
    return r;
}
/* Abre arquivo e carrega a lista para a memoria
 * Pré-condição: nenhuma
 * Pós-condição: lista carregada
*/
Lista* CarregaLista(Lista *r){
    FILE *arquivo;
    cabecalho *cab;
    r = NULL;
    arquivo = fopen("ArquivoBinarioInfo.bin","r+b");
    if(arquivo != NULL){
        cab = LeCabecalho(arquivo);
        r = CarregaMemoriaLista(arquivo,cab->pos_cabeca,r);
    }else printf("Erro ao abrir o arquivo.\n");
    fclose(arquivo);
    return r;
}
/* Carrega todo o arquivo de lista para um vetor de livros
 * Pré-condição: arquivo aberto
 * Pós-condição: um vetor com todos os livros
*/
void CarrevaAcervoVetor(FILE *arquivo,int pos,livro vet[],int *i){
    int n = *i;
    no * nolista = LeNo(arquivo,pos);
    strcpy(vet[n].autor,nolista->info.autor);
    strcpy(vet[n].titulo,nolista->info.titulo);
    vet[n].codigo = nolista->info.codigo;
    vet[n].NumExemplares = nolista->info.NumExemplares;
    n++;
    *i = n;
    if(nolista->prox != -1)
        CarrevaAcervoVetor(arquivo,nolista->prox,vet,i);
    free(nolista);
}
/* Ordena o vetor de livros apartir do autor
 * Pré-condição: vetor valido
 * Pós-condição: vetor organizado
*/
void quick_sort(livro a[], int esq, int dir) {
    int i, j;
    livro x,temp;
    i = esq;
    j = dir;
    x = a[(esq + dir) / 2];
     
    while(i <= j) {
        while(strcmp(a[i].autor , x.autor) < 0 && i < dir) {
            i++;
        }
        while(strcmp(a[j].autor , x.autor) > 0&& j > esq) {
            j--;
        }
        if(i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if(j > esq) {
        quick_sort(a, esq, j);
    }
    if(i < dir) {
        quick_sort(a, i, dir);
    }
}
/* Insere um codigo na arvore da memoria
 * Pré-condição: Nenhuma
 * Pós-condição: Codigo inserido
*/
Arvore* InsereArvore(Arvore *var,int info){
    if(var == NULL){
        var = (Arvore*)malloc(sizeof(Arvore));
        var->info = info;
        var->esq = NULL;
        var->dir = NULL; 
    }
    if(var->info < info)
        var->dir = InsereArvore(var->dir,info);
    if(var->info > info)
        var->esq = InsereArvore(var->esq,info);
    return var;
}
/* Carrega o arquivo de arvore para a memoria
 * Pré-condição: arquivo aberto
 * Pós-condição: arvore carregada para a memoria
*/
Arvore* CarregaMemoria(FILE *arquivo,int pos,Arvore *r){
    ArvoreArquivo temp;
    fseek(arquivo,pos*sizeof(ArvoreArquivo),SEEK_SET);
    int key = fread(&temp,sizeof(ArvoreArquivo),1,arquivo);
    if(key == 1 && temp.ocupado == 1){
        r = InsereArvore(r,temp.codigo);
        r = CarregaMemoria(arquivo,pos*2,r);
        r = CarregaMemoria(arquivo,(pos*2)+1,r);
    }
    return r;
}
/* Abre / fecha e carrega o arquivo de arvore para a memoria
 * Pré-condição: Nenhum
 * Pós-condição: arvore carregada para a memoria
*/
Arvore* CarregaArvoreMemoria(Arvore *r){
    FILE *arquivo;
    r = NULL;
    arquivo = fopen("ArquivoBinarioEstrutura.bin","r+b");
    if(arquivo != NULL){
        r = CarregaMemoria(arquivo,1,r);
    }else printf("Erro ao abrir o arquivo.\n");
    fclose(arquivo);
    return r;
}
/* Libera toda a arvore
 * Pré-condição: Nenhuma
 * Pós-condição: Arvore desalocada
*/
void DeleteArvore(Arvore* r){
    if(r != NULL){
        DeleteArvore(r->esq);
        DeleteArvore(r->dir);
        free(r);
    }
}
/* Retorna a altura da arvore
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
*/
int altura (Arvore *r) {
   if (r == NULL) 
      return -1; // altura da árvore vazia
   else {
      int alturaesq = altura (r->esq);
      int alturadir = altura (r->dir);
      if (alturaesq < alturadir) return alturadir + 1;
      else return alturaesq + 1;
   }
}
/* Printa a arvore por nivel
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
void printnivel(Arvore *r, int nivel,int alturaarvore){
    if(r != NULL && alturaarvore <= nivel){
        if(alturaarvore == nivel)
            printf("%d ",r->info);
    printnivel(r->esq,nivel,alturaarvore+1);
    printnivel(r->dir,nivel,alturaarvore+1);
    }
}
