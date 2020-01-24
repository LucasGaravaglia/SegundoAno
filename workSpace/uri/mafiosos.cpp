#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
#define F first
#define S second

typedef map<int, char> mp;
typedef pair<int, int> ii;

mp grafo[MAX];
int depth[MAX]; //distania de cada vertice ate a raiz
bool preso[MAX] = {false};
int qnt[MAX] = {}; //qnt-1 de vezes q o no aparece na fila de prioriade
priority_queue<ii> heap;
int n, k;

//armazena a profundidade de cada vertice e
//adiciona na fila de prioridade as folhas
void calcDepth(int id, int dp) {
   depth[id] = dp;
   bool folha = true;
   for (auto it : grafo[id]) { //para tds os filhos
      if (it.S == 'f') {
         calcDepth(it.F, dp + 1);
         folha = false;
      }
   }
   if (folha) {
      heap.push({dp, id});
   }
}

void updateAux(int id) {
   int dp = depth[id];
   bool folha = true;
   for (auto it : grafo[id]) { //para tds os filhos, atualiza
      if (it.S == 'f') {
         depth[it.F] = dp + 1;
         updateAux(it.F);
         folha = false;
      }
   }
   if (folha) { //atualiza a profundidade da folha na lista de prioridade
      qnt[id] += 1;
      heap.push({dp, id});
   }
}

//vai da folha ate a raiz atualizando a profundidade
//dos filhos nao presos recursivamente
int update(int id) {
   preso[id] = true;

   int pai = 0;
   //para todos os filhos n presos, atualiza a profundidade
   //salva o pai para continuar a busca
   for (auto it : grafo[id]) { 
      if (it.S == 'p' && !preso[it.F]) {
         pai = it.F;
      } else if (!preso[it.F]) { //atualiza a profundidade
         depth[it.F] = 0;
         updateAux(it.F);
      }
   }
   return (pai) ? 1 + update(pai) : 1;
}

int logic() {
   int cnt = 0;
   while (k--) {
      ii atual = {-1, -1};
      do {
         atual = heap.top(); heap.pop();
         if (qnt[atual.S] == 0)
            break;
         else 
            --qnt[atual.S];
      } while (!heap.empty());

      if (atual.F == -1) break;

      cnt += update(atual.S);
   }
   return cnt;
}

int main() {
   cin >> n >> k;
   for (int i = 1; i <= n - 1; ++i) {
      int u, v = i + 1;
      scanf("%d", &u);
      grafo[u].insert({v, 'f'});
      grafo[v].insert({u, 'p'});
   }
   calcDepth(1, 0); //vertice id=1, profundidade=0
   printf("%d\n", logic());
   return 0;
}