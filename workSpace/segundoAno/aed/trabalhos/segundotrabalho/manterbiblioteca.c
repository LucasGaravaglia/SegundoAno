#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"
#include "estrutura.h"
#include "menu.h"

/* Função que insere um livro no sistema
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void InsereLivro(){
    livro NovoLivro;
    ArvoreArquivo cod;

    printf("\n\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t\t\tCodigo :");
    scanf("%d%*c",&NovoLivro.codigo);
    printf("\n\t\t\t\t\t\t\t\tNumero de exemplares :");
    scanf("%d%*c",&NovoLivro.NumExemplares);
    printf("\n\t\t\t\t\t\t\t\tTítulo :");
    scanf("%[^\n]%*c",NovoLivro.titulo);
    printf("\n\t\t\t\t\t\t\t\tAutor :");
    scanf("%[^\n]%*c",NovoLivro.autor);
    cod.codigo = NovoLivro.codigo;
    cod.ocupado = 1;
    

    FILE *arquivoestrutura;
    FILE *arquivoinfo;
    arquivoestrutura = fopen("ArquivoBinarioEstrutura.bin","r+b");
    arquivoinfo = fopen("/ArquivoBinarioInfo.bin","r+b");
    if(arquivoestrutura != NULL && arquivoinfo != NULL){
        if(!BuscarLivroArvore(arquivoestrutura,cod.codigo,1)){
            InsereCodigoArquivoBin(cod,arquivoestrutura,1);
            InsereLivroLista(arquivoinfo,NovoLivro);
            printf("\n\n\t\t\t\t\t\t\t\tLivro inserido com sucesso.\n");
        }else printf("\n\n\t\t\t\t\t\t\t\tCodigo já existente.\n");
    }else printf("\n\t\t\t\t\t\t\t\tErro ao abrir o arquivo.");
    fclose(arquivoestrutura);
    fclose(arquivoinfo);
    backmenu();
}
/* Função que atualiza o n de exemplar de algum livro
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum:
*/
void atualizaexemplares(){
    int info;
    int nexemplares;
    printf("\n\t\t\t\t\t\t\t\tCodigo: ");
    scanf("%d%*c",&info);
    printf("\n\t\t\t\t\t\t\t\tNumero exemplares: ");
    scanf("%d%*c",&nexemplares);
    FILE *arquivoestrutura;
    FILE *arquivoinfo;
    arquivoestrutura = fopen("ArquivoBinarioEstrutura.bin","r+b");
    arquivoinfo = fopen("ArquivoBinarioInfo.bin","r+b");
    if(arquivoestrutura != NULL && arquivoinfo != NULL){
        if(BuscarLivroArvore(arquivoestrutura,info,1)){
            AlterarExemplares(arquivoinfo,info,nexemplares);
            printf("\n\n\t\t\t\t\t\t\t\tNumero exemplar alterado com sucesso.\n");
        }else printf("\n\n\t\t\t\t\t\t\t\tCodigo não encontrado.\n");
    }else printf("\n\t\t\t\t\t\t\t\tErro ao abrir o arquivo.");
    fclose(arquivoestrutura);
    fclose(arquivoinfo);
    backmenu();
}
/* Função que remove um livro do sistema
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void RemoveLivroCadastro(){
    int info;
    int key;
    FILE *arquivoestrutura;
    FILE *arquivoinfo;
    printf("\n\t\t\t\t\t\t\t\tCodigo do livro a ser removido: ");
    scanf("%d%*c",&info);
    arquivoestrutura = fopen("ArquivoBinarioEstrutura.bin","r+b");
    arquivoinfo = fopen("ArquivoBinarioInfo.bin","r+b");
    if(arquivoestrutura != NULL && arquivoinfo != NULL){
        key = RemoveCodigoArquivoBin(info,arquivoestrutura,1); 
        if(key){
            RetiraLivroLista(arquivoinfo,info);
            printf("Livro removido com sucesso.\n");
        }else printf("Erro ao remover o livro.\n");
    }else printf("\n\t\t\t\t\t\t\t\tErro ao abrir o arquivo.");
    fclose(arquivoestrutura);
    fclose(arquivoinfo);
    backmenu();
}
/* Função que busca e printa os dados de um determinado livro
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void BuscaDadoLivro(){
    int info;
    int pos;
    FILE *arquivoestrutura;
    FILE *arquivoinfo;
    printf("\n\t\t\t\t\t\t\t\tCodigo do livro a ser mostrado: ");
    scanf("%d%*c",&info);
    arquivoestrutura = fopen("ArquivoBinarioEstrutura.bin","r+b");
    arquivoinfo = fopen("ArquivoBinarioInfo.bin","r+b");
    if(arquivoestrutura != NULL && arquivoinfo != NULL){
        if(BuscarLivroArvore(arquivoestrutura,info,1)){
            Procura_printaLivro_Lista(arquivoinfo,info);
        }else printf("Livro nao encontrado.\n");
    }else printf("\n\t\t\t\t\t\t\t\tErro ao abrir o arquivo.\n");
    fclose(arquivoestrutura);
    fclose(arquivoinfo);
    backmenu();

}
/* Função que imprime a arvore de codigos
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void ImprimiArvore(){    
    Arvore *r = CarregaArvoreMemoria(r);
    ImprimiArvoreBinaria(r,1);
    DeleteArvore(r);
    backmenu();
}
/* Função que carrega o arquivo inicial para o sistema
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void LoadFile(){
    FILE *arquivo;
    FILE *arquivobininfo;
    FILE *arquivobinarvore;
    livro info;
    ArvoreArquivo cod;
    char nomearquivo[500];
    char temp[200];
    printf("Nome do arquivo: ");
    scanf("%s",&nomearquivo);
    arquivo = fopen(nomearquivo,"r");
    cod.ocupado = 1;

    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        fclose(arquivo);
        backmenu();
    }else{
        arquivobinarvore = fopen("ArquivoBinarioEstrutura.bin","w+b");
        arquivobininfo = fopen("ArquivoBinarioInfo.bin","r+b");
        while(!feof(arquivo)){
            fscanf(arquivo,"%d%*c",&info.codigo);
            cod.codigo = info.codigo;
            fscanf(arquivo,"%[^;]%*c",temp);
            removeSpaces(temp);
            strcpy(info.titulo,temp);
            fscanf(arquivo,"%[^;]%*c",temp);
            removeSpaces(temp);
            strcpy(info.autor,temp);
            fscanf(arquivo,"%d%*c%*r",&info.NumExemplares);
            InsereLivroLista(arquivobininfo,info);
            InsereCodigoArquivoBin(cod,arquivobinarvore,1);
        }
        printf("Arquivo inserido com sucesso.\n");
    }
    fclose(arquivobinarvore);
    fclose(arquivobininfo);
    fclose(arquivo);
    backmenu();
}
/* Função que imprimi a arvore de codigos por nivel
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void ImprimiArvoreNivel(){
    Arvore *r = CarregaArvoreMemoria(r);
    int tamanho = altura(r)+1;
    for(int i=0;i<=tamanho;i++){
        printnivel(r,i,0);
        printf("\n");
    }
    DeleteArvore(r);
    backmenu();
}
/* Função que imprime os dados de todo o acervo
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void ImprimeAcervo(){
    Lista *l = CarregaLista(l);
    Lista *temp = l;
    system("clear");
    while (l != NULL){
        printf("---------------------------------------------\n");
        printf("Codigo: %d\n",l->info.codigo);
        printf("Autor: %s\n",l->info.autor);
        printf("Numero de Exemplares: %d\n",l->info.NumExemplares);
        printf("Titulo: %s\n",l->info.titulo);
        l = l->prox;
    }
    DeleteLista(temp);
    backmenu();
}
/* Função que gera um arquivo ordenado lexicograficamente com todo o acervo
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void ListaLivrosOrdenado(){
    FILE *arquivo;
    livro vet[200];
    int tam = 0;
    arquivo = fopen("ArquivoBinarioInfo.bin","r+b");
    cabecalho *cab = LeCabecalho(arquivo);
    CarrevaAcervoVetor(arquivo,cab->pos_cabeca,vet,&tam);
    quick_sort(vet,0,tam-1);
    free(cab);
    fclose(arquivo);
    FILE *f;
    f = fopen("Listalivros.txt","w");
    for(int i=0;i<tam;i++){
        fprintf(f,"Codigo: %d\n",vet[i].codigo);
        fprintf(f,"Autor: %s\n",vet[i].autor);
        fprintf(f,"Titulo: %s\n",vet[i].titulo);
        fprintf(f,"Numero de exemplares: %d\n",vet[i].NumExemplares);
        fprintf(f,"---------------------------------------------------------------\n");
    }
    printf("Arquivo criado com sucesso.\n");
    fclose(f);
    backmenu();
}