#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

// estrutura de nó para lista encadeada
typedef struct no {
int info;
struct no *prox;
}pilha;
// Testa se uma pilha é vazia
// Entrada: pilha
// Retorno: 1 se a pilha é vazia ou 0 caso contrário
// Pré-condiçao: nenhuma
// Pós-condiçao: nenhuma
int vazia(pilha * st);
// Empilha um elemento na pilha
// Entrada: pilha e inteiro a ser empilhado
// Retorno: pilha alterada
// Pré-condiçao: nenhuma
// Pós-condiçao: elemento é empilhado
pilha* push(pilha* st, int info);
// Desempilha um elemento da pilha
// Entrada: pilha
// Retorno: pilha alterada
// Pré-condiçao: nenhuma
// Pós-condiçao: elemento do topo é removido
pilha* pop(pilha* st);
// Le o topo da pilha
// Entrada: pilha
// Retorno: elemento do topo da pilha ou -1 se a pilha está vazia
// Pré-condiçao: nenhuma
// Pós-condiçao: retorna o topo da pilha
int topo(pilha* st);
// Imprime os elementos da pilha
// Entrada: pilha
// Retorno: nenhum
// Pré-condiçao: nenhuma
// Pós-condiçao: os elementos sao impressos no console
void imprime(pilha* st);

#endif // PILHA_H
