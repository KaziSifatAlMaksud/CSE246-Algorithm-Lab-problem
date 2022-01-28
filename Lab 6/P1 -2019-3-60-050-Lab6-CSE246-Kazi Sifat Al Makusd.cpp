#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
void addEdge(int i, int j)
{
        adj[i][j] = 1;
        adj[i][j] = 1;
}


void dfs(int start, vector<bool>& visited, vector<int>& count)
{

        count.push_back(start);


        visited[start] = true;


        for (int i = 0; i < adj[start].size(); i++) {

                if (adj[start][i] == 1 && (!visited[i])) {
                        dfs(i, visited, count);
                }
        }
}

int main()
{

        int v,e,x,y;
        printf("enter vertex and edges: ");
        scanf("%d%d",&v,&e);


        adj = vector<vector<int> >(v, vector<int>(v, 0));
        for(int i = 0;i<e;i++){
                scanf("%d%d",&x,&y);
            addEdge(x, y);
        }
        vector<bool> visited(v, false);
    vector<int> count;

        dfs(0, visited, count);

        if(count.size()==v)
        cout<<"The graph is connected"<<endl;

        else cout<<"The graph is disconnected"<<endl;
}
