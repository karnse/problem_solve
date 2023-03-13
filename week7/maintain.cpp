#include <bits/stdc++.h>
using namespace std;
int n, m;
int g[210][210];
int visited[210];
vector<int> loopi;
int loopios;
int chk;
int ans;
int cntans;
void dfs(int now, int parent)
{
    if (loopios != -1)
        return;
    visited[now] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (loopios != -1)
            break;
        if (g[now][i])
        {
            if (i == parent)
                continue;
            if (visited[i])
            {
                loopios = i;
                chk = 1;
                loopi.push_back(i);
                break;
            }
            else
            {
                dfs(i, now);
            }
        }
    }
    if (chk)
    {
        loopi.push_back(now);
        if (now == loopios)
            chk = 0;
    }
    visited[now] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(g, 0, sizeof(g));
    ans = 0;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (g[u][v] == 0)
        {
            g[u][v] = w;
            g[v][u] = w;
            ans += w;
            cntans++;
            loopi.clear();
            memset(visited, 0, sizeof(visited));
            loopios = -1;
            chk = 0;
            dfs(u, -1);
            if (loopios != -1)
            {
                int maxv = 0;
                int maxposu = 0;
                int maxposv = 0;
                for (int i = 0; i < loopi.size() - 1; i++)
                {
                    // cout<<' '<<loopi[i]<<' '<<loopi[i+1]<<' '<<g[loopi[i]][loopi[i+1]]<<'\n';
                    if (g[loopi[i]][loopi[i + 1]] > maxv)
                    {
                        maxv = g[loopi[i]][loopi[i + 1]];
                        maxposu = loopi[i];
                        maxposv = loopi[i + 1];
                    }
                }
                ans -= maxv;
                g[maxposu][maxposv] = 0;
                g[maxposv][maxposu] = 0;
                cntans--;
            }
        }
        else if (g[u][v] > w)
        {
            ans -= g[u][v];
            g[u][v] = w;
            g[v][u] = w;
            ans += w;
        }
        if (cntans == n - 1)
        {
            cout << ans << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}