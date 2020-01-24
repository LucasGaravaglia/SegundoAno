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

vii grafo[MAXN];
int n; //num vertices

int dijkstra(int src, int dst) { //O(Elg(V))
   int dist[MAXN];
   for (int i = 1; i <= n; ++i) {
      dist[i] = INF;
   }
   dist[src] = 0;

   priority_queue<ii, vector<ii>, greater<ii>> heap;
   heap.push(ii(0, src));

   while (!heap.empty()) {
      ii top = heap.top(); heap.pop();
      int u = top.S; int d = top.F;

      if (d > dist[u]) continue;

      for (int i = 0; i < grafo[u].size(); ++i) {
         ii v = grafo[u][i];
         if (dist[u] + v.S < dist[v.F]) {
            dist[v.F] = dist[u] + v.S;
            heap.push(ii(dist[v.F], v.F));
         }
      }
   }
   return dist[dst];
}

int main() {
   n = 3;
   grafo[1].push_back(ii(2, 10));
   grafo[2].push_back(ii(1, 10));
   grafo[3].push_back(ii(2, 20));
   grafo[2].push_back(ii(3, 20));
   printf("%d\n", dijkstra(1,3));
   return 0;
}