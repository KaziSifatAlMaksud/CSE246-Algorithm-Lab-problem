// Kruskal's algorithm in C++

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;
  vector<pair<int, edge> > T;
    int *parent;
    int V;
   public:
  Graph(int V);

};
void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
Graph(int V) {
  parent = new int[V];
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int find_set(int i) {
  if (i == parent[i])
    return i;
  else
    return find_set(parent[i]);
}

void union_set(int u, int v) {
  parent[u] = parent[v];
}
void kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
}
void print() {
    printf("Edge : Weight \n");
    int a;
  for (int i = 0; i < T.size(); i++) {
    a = T[i].second.first;
    b = T[i].second.second;
    t = T[i].first;
    printf("%d   -     %d      : %d\n",a,b,t);

  }
}
int main() {
    int n,e,u,v,w;
    scanf("%d",&n);
    scanf("&d",&e);
  Graph g(n);
  for(int i =0;i<e;i++){
    scanf("%d",&u);
    scanf("%d",&v);
    scanf("%d",&w);
    AddWeightedEdge(u,v,w);
  }
  kruskal();
  print();
  return 0;
}
