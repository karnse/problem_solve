#include<bits/stdc++.h>
using namespace std;
int deg[100100];
int last;
int ans;
int visited[100100];
vector<int> g[100100];
vector<int> starpat;
map<vector<int>,int> mapp;
map<int,int> mapp2;
priority_queue<pair<int,int> > q;
int dfs(int now)
{
    if(visited[now])
        return 0;
    visited[now]=1;
    for(auto y:g[now])
        if(!visited[y])
            return dfs(y)+1;
    if(deg[now]==2)
        return 100001;
    return 1;
}
void dfschk3(int now)
{
    visited[now]=1;
    starpat.clear();
    for(auto x: g[now])
    {
        starpat.push_back(dfs(x));
    }
    sort(starpat.begin(),starpat.end());
    // cout<<"3 "<<now<<": ";
    // for(auto x:starpat)
    //     cout<<x<<' ';
    mapp[starpat]++;
}
void dfschk2(int now)
{
    visited[now]=1;
    starpat.clear();
    for(auto x: g[now])
    {
        starpat.push_back(dfs(x));
    }
    sort(starpat.begin(),starpat.end());
    if(starpat[0])
    {
        starpat[0]+=starpat[1];
        starpat.pop_back();
    }
    // cout<<"2 "<<now<<": ";
    // for(auto x: starpat)
    //     cout<<x<<' ';
    // cout<<"\n";
    mapp[starpat]++;
}
void dfschk1(int now)
{
    visited[now]=1;
    int tmp=dfs(g[now][0]);
    mapp2[tmp]++;
    // cout<<"1 "<<now<<": "<<tmp<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        int s,t;
        cin>>s>>t;
        g[s].push_back(t);
        g[t].push_back(s);
        deg[s]++;
        deg[t]++;
    }
    for(int i = 1;i <= n; i++)
    {
        q.push(make_pair(deg[i],i));
    }
    int ind;
    while(!q.empty())
    {
        ind = q.top().second;
        q.pop();
        if(deg[ind]==3&&!visited[ind])
            dfschk3(ind);
        if(deg[ind]==2&&!visited[ind])
            dfschk2(ind);
        if(deg[ind]==1&&!visited[ind])
            dfschk1(ind);
        if(deg[ind]==0&&!visited[ind])
        {
            ans++;
            break;
        }
    }
    ans+=mapp.size()+mapp2.size();
    cout<<ans;
    return 0;
}