//// estrutura de nó para lista encadeada
//typedef struct no{
//    int info;
//    struct no *prox;
//}FilaNo;
//// estrutura para fila
//typedef struct fila{
//    int n; // número de elementos
//    struct no* prim;
//    struct no* ultimo;
//}Fila;
//// Testa se a fila está vazia
//// Entrada: fila
//// Retorno: 1 se a fila é vazia ou 0 caso contrário
//// Pré-condiçao: ponteiro nao nulo p/ estrutura fila
//// Pós-condiçao: nenhuma
//int vazia(Fila* f);
//// Insere um elemento na fila
//// Entrada: fila e inteiro a ser inserido
//// Retorno: nenhum
//// Pré-condiçao: ponteiro nao nulo para estrutura fila
//// Pós-condiçao: elemento é inserido na fila
//void enqueue(Fila* f, int info);
//// Remove um elemento da fila
//// Entrada: fila e inteiro a ser removido
//// Retorno: nenhum
//// Pré-condiçao: ponteiro nao nulo para estrutura fila
//// Pós-condiçao: elemento é removido da fila
//void dequeue(Fila* f);
//// Imprime os elementos da fila
//// Entrada: fila
//// Retorno: nenhum
//// Pré-condiçao: ponteiro nao nulo para estrutura fila
//// Pós-condiçao: os elementos sao impressos no console
//void imprime(Fila* f);
//void inverte(Fila* f);
