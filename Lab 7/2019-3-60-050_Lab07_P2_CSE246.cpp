#include<stdio.h>
#include<vector>

using namespace std;
struct edge
{
        int src, dest, weight;
}temp;

int n;
int dis[100], par[100];
vector<edge> edgeList;

int print_shortest_path(int src,int dest){
    if(src == dest){
        printf("%d",src);
        return 1;
    }
    int ok;
    if(par[dest] != -1){
        ok = print_shortest_path(src,par[dest]);
    }
    else{
        return -1;
    }
    if(ok!= -1){
        printf(" -> %d",dest);
    }
    else{
        return -1;
    }
    return 1;
}

void bellmen_ford(int src)
{
        for(int i=0; i<n-1;i++){
            for(int j =0 ; j < edgeList.size();j++){
                int u = edgeList[j].src;
                int v = edgeList[j].dest;
                int w = edgeList[j].weight;
                if (dis[v] > dis[u] + w && dis[u] != 99999){
                        dis[v] = dis[u] + w;
                        par[v] = u;
                }
            }
        }
        for(int j =0 ; j < edgeList.size();j++){
                int u = edgeList[j].src;
                int v = edgeList[j].dest;
                int w = edgeList[j].weight;
                if(dis[u]!= 99999 && dis[u]+w < dis[v]){
                        printf("Graph contains negative w cycle \n");
                return;
            }
        }

}

int main()
{   int u, v, w, i;
    int e;
    printf("Vertex, edges: ");
    scanf("%d %d", &n, &e);
    for (i = 0; i < e; i++){
        scanf("%d %d %d", &u, &v, &w);
        temp.src = u;
        temp.dest = v;
        temp.weight = w;
        edgeList.push_back(temp);
    }
    for (i = 0; i < n; i++){
        dis[i] = 99999;
        par[i] = -1;
    }
    int src = 0;
    dis[src] = 0;
    bellmen_ford(src);
    for (i = 0; i < n; i++){
        printf(" %d",dis[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
            if(i!= src){
                printf("shortest path from %d to %d: ",src,i);
                int found = print_shortest_path(src,i);
                if(found!= -1){
                    printf("\n");
                }
                else{
                    printf("No possible path\n");
                }
            }
        }
    return 0;
}
/*
4 5
0 3 10
0 1 1
0 2 1
3 1 -100
1 2 2
 */

