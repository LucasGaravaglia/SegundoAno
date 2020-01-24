#ifndef ARQUIVO_H
#define ARQUIVO_H

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
void removeSpaces(char s[]);
/* Função que procura um codigo no arquivo de arvore
 * Pré-condição: Arquivo aberto, e posição valida.
 * Pós-condição: Posição no arquivo do codigo.
*/
int procurar(FILE* arquivoinfo,int pos_atual, int info);
/* Altera quantidade de exemplares de um determinado livro
 * Pré-condição: Arquivo de lista aberto
 * Pós-condição: Num de exemplares alterado
*/
void AlterarExemplares(FILE *arquivoinfo,int info,int nexemplares);
/* Procura e printa um livro a partir de seu codigo
 * Pré-condição: Livro existente na lista, arquivo de lista aberto
 * Pós-condição: Nenhuma
*/
void Procura_printaLivro_Lista(FILE *arquivoinfo,int info);
/* Busca um livro no arquivo de arvore
 * Pré-condição: arquivo aberto.
 * Pós-condição: true caso o livro exista e false caso contrario
*/
int BuscarLivroArvore(FILE *arquivo,int info,int pos);
/* Insere um codigo no arquivo de arvore
 * Pré-condição: Arquivo aberto
 * Pós-condição: Arquivo inserido
*/
void InsereCodigoArquivoBin(ArvoreArquivo r,FILE *arquivo,int pos);
/* Retorna o menor codigo da arvore
 * Pré-condição: Arquivo aberto
 * Pós-condição: valor do menor codigo da arvore
*/
int mincodigo(FILE *arquivo,int pos);
/* Retorna o maior codigo da arvore
 * Pré-condição: Arquivo aberto
 * Pós-condição: Valor do maior codigo da arvore
*/
int maxcodigo(FILE *arquivo,int pos);
/* Remove um codigo do arquivo de arvore
 * Pré-condição: Arquivo aberto
 * Pós-condição: True caso removido ou false caso contrario
*/
int RemoveCodigoArquivoBin(int info,FILE *arquivo,int pos);
/* Le o cabeçalho do arquivo contendo as informaçoes da lista
 * Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
 * Pós-condição: retorna o ponteiro para o cabeçalho lido
*/
cabecalho* LeCabecalho(FILE * arq);
/* Escreve no arquivo o cabeçalho contendo as informaçoes da lista
 * Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
 * Pós-condição: cabeçalho escrito no arquivo
*/
void EscreveCabecalho(FILE* arq, cabecalho* cab);
/* le um nó em uma determinada posiçao do arquivo
 * Pré-condição: arquivo deve estar aberto e ser um arquivo de lista,pos deve ser uma posiçao válida da lista
 * Pós-condição: ponteiro para nó lido é retornado
*/
no* LeNo(FILE* arq, int pos);
/* Escreve um nó 
 * Pré-condição: Nenhuma
 * Pós-condição:em uma determinada posiçao do arquivo arquivo deve estar aberto e ser um arquivo de lista pos deve ser uma posiçao válida do arquivo nó escrito no arquivo
*/
void EscreveNo(FILE* arq, no* x, int pos);
/* Insere um nó na lista
 * Pré-condição: arquivo aberto
 * Pós-condição: nó inserido
*/
void InsereLivroLista(FILE* arq, livro info);
/* Retira um nó da lista
 * Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
 * Pós-condição: nó retirado da lista caso pertença a ela
*/
void RetiraLivroLista(FILE* arq, int x);
/* Cria uma lista nova em arquivo
 * Pré-condiçao: arquivo aberto para leitura/escrita
 * Pós-condiçao: arquivo é inicializado com uma lista vazia
*/
void cria_lista_vazia();
/* Imprime arvore com [,]
 * Pré-condição: arvore carregada para a memoria
 * Pós-condição: nenhuma
*/
void ImprimiArvoreBinaria(Arvore *r,int pos);
/* Insere um livro na lista em ordem crescente a partir do codigo
 * Pré-condição: nenhuma
 * Pós-condição: livro inserido ordenado 
*/
Lista* InsereListaOrdenado(Lista* l, livro info);
/* Função para apagar toda a lista de livro
 * Pré-condição: Nenhuma
 * Pós-condição: Lista limpa
*/
void DeleteLista(Lista* l);
/* Carrega todo o arquivo de lista para a memoria em ordem
 * Pré-condição: arquivo aberto
 * Pós-condição: uma lista de livros na memoria
*/
Lista* CarregaMemoriaLista(FILE *arquivo,int pos,Lista *r);
/* Abre arquivo e carrega a lista para a memoria
 * Pré-condição: nenhuma
 * Pós-condição: lista carregada
*/
Lista* CarregaLista(Lista *r);
/* Carrega todo o arquivo de lista para um vetor de livros
 * Pré-condição: arquivo aberto
 * Pós-condição: um vetor com todos os livros
*/
void CarrevaAcervoVetor(FILE *arquivo,int pos,livro vet[],int *i);
/* Ordena o vetor de livros apartir do autor
 * Pré-condição: vetor valido
 * Pós-condição: vetor organizado
*/
void quick_sort(livro a[], int esq, int dir);
/* Insere um codigo na arvore da memoria
 * Pré-condição: Nenhuma
 * Pós-condição: Codigo inserido
*/
Arvore* InsereArvore(Arvore *var,int info);
/* Carrega o arquivo de arvore para a memoria
 * Pré-condição: arquivo aberto
 * Pós-condição: arvore carregada para a memoria
*/
Arvore* CarregaMemoria(FILE *arquivo,int pos,Arvore *r);
/* Abre / fecha e carrega o arquivo de arvore para a memoria
 * Pré-condição: Nenhum
 * Pós-condição: arvore carregada para a memoria
*/
Arvore* CarregaArvoreMemoria(Arvore *r);
/* Libera toda a arvore
 * Pré-condição: Nenhuma
 * Pós-condição: Arvore desalocada
*/
void DeleteArvore(Arvore* r);
/* Retorna a altura da arvore
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
*/
int altura(Arvore *r);
/* Printa a arvore por nivel
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
void printnivel(Arvore *r, int nivel,int alturaarvore);

#endif