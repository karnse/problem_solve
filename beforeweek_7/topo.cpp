#include <bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int mem[100100];
int in[100100];
queue<int> q;
int dfs(int now, int color)
{
    int ans = 1;
    int nextc = 3 - color;
    for (auto x : g[now])
    {
        if (!mem[x])
        {
            mem[x] = nextc;
            ans = min(ans, dfs(x, nextc));
        }
        else if (mem[x] == color)
            return 0;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 1;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, t;
        cin >> s >> t;
        g[s].push_back(t);
        in[t]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!ans)
            break;
        if (!mem[i])
        {
            mem[i] = 1;
            ans = dfs(i, 1);
        }
    }
    int alr=0;
    for(int i = 1; i <= n; i++)
    {
        if(!in[i])
        {
            q.push(i);
            cout<<i<<'\n';
        }
    }
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        alr++;
        for(auto x:g[now])
        {
            in[x]--;
            if(!in[x])
            {
                q.push(x);
                cout<<x<<'\n';
            }
        }
    }
    return 0;
}