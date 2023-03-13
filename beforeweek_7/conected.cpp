#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int visited[100100];
void dfs(int now)
{
    visited[now]=1;
    for(auto i:g[now])
    {
        if(!visited[i])
        {
            visited[i]=1;
            dfs(i);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        int s,t;
        cin>>s>>t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    int count=0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            count++;
        }
    }
    cout<<count;
    return 0;
}