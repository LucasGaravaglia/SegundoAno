#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 10010
#define F first
#define S second
#define INF 0x3f3f3f3f

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef struct aresta {
   int u, v, p;
} Aresta;

Aresta grafo[MAXN];
int dist[MAXN]; //distancias
int n, e; //num vertices e arestas

bool bFord(int src) { //O(v^2)
   for (int i = 1; i <= n; ++i) {
      dist[i] = INF;
   }
   dist[src] = 0;
   for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < e; ++j) {
         int u = grafo[j].u, v = grafo[j].v;
         int p = grafo[j].p;
         if (dist[u] + p < dist[v] && dist[u] != INF) {
            dist[v] = dist[u] + p;
         }
      }
   }
   for (int j = 0; j < e; ++j) {
      int u = grafo[j].u, v = grafo[j].v;
      int p = grafo[j].p;
      if (dist[u] + p < dist[v] && dist[u] != INF) {
         return false; //ciclo negativo identificado
      }
   }
   return true;
}

int main() {
   n = 3; e = 2;
   grafo[0].u = 1; grafo[0].v = 2;  grafo[0].p = 10;
   grafo[1].u = 2; grafo[1].v = 3;  grafo[1].p = 20;
   if (bFord(1))
      printf("%d\n", dist[2]);
   else 
      printf("ciclo de peso negativo\n");
   return 0;
}