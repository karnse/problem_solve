#include<bits/stdc++.h>
using namespace std;
int par[100100];
priority_queue<pair<int,pair<int,int> > > q;
int findroot(int now)
{
    if(par[now] == now)
        return now;
    return par[now] = findroot(par[now]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        par[i]=i;
    }
    for(int i = 0; i < m; i++)
    {
        int val,x,y;
        cin >> x>>y>>val;
        q.push(make_pair(-val,make_pair(x,y)));
    }
    int ans=0;
    while(!q.empty())
    {
        pair<int,pair<int,int> > now=q.top();
        now.first *=-1;
        q.pop();
        if(findroot(now.second.first)!=findroot(now.second.second))
        {
            par[findroot(now.second.first)]=findroot(now.second.second);
            ans+=now.first;
        }
    }
    cout<<ans;
    return 0;
}