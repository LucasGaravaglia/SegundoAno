#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 10010
#define INF 0x3f3f3f3f

typedef vector<int> vi;

int n; //num vertices
int dist[MAXN][MAXN];
int prox[MAXN][MAXN];
int grafo[MAXN][MAXN];

void fWarshall() { //O(v^3)
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         dist[i][j] = grafo[i][j];
         if (i == j) {
            prox[i][j] = 0;
         } else if (grafo[i][j] != INF) {
            prox[i][j] = j;
         } else {
            prox[i][j] = -1; //null
         }
      }
   }
   for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
            if (dist[i][k] + dist[k][j] < dist[i][j]) {
               dist[i][j] = dist[i][k] + dist[k][j];
               prox[i][j] = prox[i][k];
            }
         }
      }
   }
}

vi path(int u, int v) {
   vi res; res.reserve(MAXN);
   if (prox[u][v] == -1) return res;
   res.push_back(u);
   while (u != v) {
      u = prox[u][v];
      res.push_back(u);
   }
   return res;
}

int main() {
   n = 3;
   grafo[0][0] = 0; grafo[0][1] = 20; grafo[0][2] = INF; 
   grafo[1][0] = INF; grafo[1][1] = 0; grafo[1][2] = 10; 
   grafo[2][0] = INF; grafo[2][1] = INF; grafo[2][2] = 0; 
   fWarshall();
   vi res = path(1, 0);
   for (int i = 0; i < res.size(); ++i) {
      printf("%d ", res[i]);
   }
   printf("\n");
   return 0;
}