#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int mem[100100];
int dfs(int now,int color)
{
    int ans=1;
    int nextc = 3-color;
    for(auto x:g[now])
    {
        if(!mem[x]){
            mem[x]= nextc;
            ans = min(ans,dfs(x,nextc));
        }
        else if(mem[x]==color)
            return 0;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >>q;
    while(q--)
    {
        int ans=1;
        int n,m;
        cin>>n>>m;
        for(int i = 0; i < m; i++)
        {
            int s,t;
            cin>>s>>t;
            g[s].push_back(t);
            g[t].push_back(s);
        }
        for(int i = 1; i <= n; i++)
        {
            if(!ans)
                break;
            if(!mem[i]){
                mem[i]=1;
                ans = dfs(i,1);
            }
        }
        for(int i = 1; i <= n; i++)
        {
            g[i].clear();
            mem[i]=0;
        }
        cout<< (ans ? "yes":"no") << '\n';
    }
    return 0;
}