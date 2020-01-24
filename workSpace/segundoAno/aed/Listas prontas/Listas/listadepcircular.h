
#include <stdio.h>
#include <stdlib.h>
// estrutura de nó para lista duplamente encadeada circular
typedef struct no {
    int info;
    struct no *ant;
    struct no *prox;
} Lista;

// Testa se uma lista é vazia
// Entrada: lista
// Retorno: 1 se a lista é vazia ou 0 caso contrário
// Pré-condiçao: nenhuma
// Pós-condiçao: nenhuma
int vaziadupCir(Lista * l);

// Insere um elemento na lista
// Entrada: lista e elemento a ser inserido
// Retorno: lista alterada
// Pré-condiçao: nenhuma
// Pós-condiçao: elemento é inserido na lista
Lista* inseredupCir(Lista* l, int info);

// Remove um elemento da lista
// Entrada: lista e elemento a ser removido
// Retorno: lista alterada
// Pré-condiçao: nenhuma
// Pós-condiçao: elemento é removido da lista
Lista* removedupCir(Lista* l, int info);

// Imprime os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pré-condiçao: nenhuma
// Pós-condiçao: os elementos sao impressos no console
void imprimedupCir(Lista* l);

// Inverte uma lista
// Entrada: lista
// Retorno: lista invertida
// Pré-condiçao: nenhuma
// Pós-condiçao: lista original nao é modificada
Lista* invertedupCir(Lista* l);

// Concatena duas listas
// Entrada: listas a serem concatenadas
// Retorno: lista resultante da concatenaçao
// Pré-condiçao: nenhuma
// Pós-condiçao: listas originais nao sao modificadas
Lista* concatenadupCir(Lista* l1, Lista* l2);

// Intercala duas listas
// Entrada: listas a serem intercaladas
// Retorno: lista resultante da intercalaçao
// Pré-condiçao: nenhuma
// Pós-condiçao: listas originais permanecem inalteradas
Lista* mergedupCir(Lista* l1, Lista* l2);

