#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 100010;

int m, n;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        deg[i] = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--; //ให้node 1เป็น node 0 เริ่มindex0

        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}

bool seen[MAX_N];
int layer[MAX_N];
int color[MAX_N];
bool isbipartite;

void init()
{
    for (int u = 0; u < n; u++)
    {
        seen[u] = false;
        layer[u] = -1;
        color[u] = 0;
        isbipartite = true;
        adj[u].clear();
        deg[u]=0;
    }

}

void bfs(int s) // s=ตัวเริ่ม
{
    list<int> Q;

    Q.push_back(s);
    color[s]= 1;
    seen[s] = true;
    layer[s] = 0;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop_front();
        for (int d = 0; d < deg[u]; d++)
        {
            int v = adj[u][d];
            if (!seen[v])
            {
                Q.push_back(v);
                color[v] = 1-color[u];
                seen[v] = true;
                layer[v] = layer[u] + 1;
            }
            else
            {
                if(color[v]==color[u])
                {
                    isbipartite=false;
                    Q.clear();
                    return;
                }
            }

        }
    }

}

int main()
{
    int k;
    cin >> k;
    for(int i=0; i<k; i++)
    {
        init();
        read_input();

        for(int j=0; j<n ;j++)
        {
            if(!seen[j])
                bfs(j);
        }
        if(isbipartite)
            cout << "yes" <<"\n";
        else
            cout << "no" <<"\n";
    }

}