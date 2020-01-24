#ifndef MANTERBIBLIOTECA_H
#define MANTERBIBLIOTECA_H

/* Função que insere um livro no sistema
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void InsereLivro();
/* Função que atualiza o n de exemplar de algum livro
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum:
*/
void atualizaexemplares();
/* Função que remove um livro do sistema
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void RemoveLivroCadastro();
/* Função que busca e printa os dados de um determinado livro
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void BuscaDadoLivro();
/* Função que imprime a arvore de codigos
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void ImprimiArvore();
/* Função que carrega o arquivo inicial para o sistema
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void LoadFile();
/* Função que imprimi a arvore de codigos por nivel
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void ImprimiArvoreNivel();
/* Função que imprime os dados de todo o acervo
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void ImprimeAcervo();
/* Função que gera um arquivo ordenado lexicograficamente com todo o acervo
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void ListaLivrosOrdenado();


#endif