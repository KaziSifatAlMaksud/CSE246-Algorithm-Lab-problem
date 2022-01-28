#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;


void addEdge(int x, int y)
{
        adj[x][y] = 1;
        adj[y][x] = 1;
}

void pathPrint(vector<int>& path)
{
        int size = path.size();
        for (int i = 0; i < size; i++)
            if(i!=size-1)
                    cout << path[i] << "->";
                else cout << path[i];
        cout << endl;
}

int alreadyExist(int x, vector<int>& path)
{
        int size = path.size();
        for (int i = 0; i < size; i++)

                if (path[i] == x)
                        return 0;
        return 1;
}

void solvePaths(vector<vector<int>> adj, int src,int dst, int v)
{

        queue<vector<int> > q;


        vector<int> path;

        path.push_back(src);
        q.push(path);

        while (!q.empty()) {
                path = q.front();
                q.pop();
                int last = path[path.size() - 1];

                if (last == dst)
                    {
                        pathPrint(path);
                        break;
                    }

                for (int i = 0; i < v; i++) {
                    if(i!=last && adj[last][i]==1)
                    {
                        if (alreadyExist(i, path)) {
                                vector<int> updatedPath(path);
                                updatedPath.push_back(i);
                                q.push(updatedPath);
                        }
                    }
                }
        }
}


int main()
{
    int v,e,x,y;
        printf("Enter how many vertex , eges: ");
        scanf("%d%d",&v,&e);
        scanf("%d%d",&x,&y);


        adj = vector<vector<int> >(v, vector<int>(v, 0));
        for(int i=0;i<e;i++){
        scanf("%d%d",&x,&y);
        addEdge(x, y);
}

        int src = 0;

        for(int i=0;i<v;i++)
        if(i!=src)
        solvePaths(adj, src, i, v);

        return 0;
}
