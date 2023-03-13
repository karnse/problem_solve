#include<bits/stdc++.h>
using namespace std;
int par[100100];
int findpar(int now)
{
    if(par[now] == now)
        return now;
    return par[now] = findpar(par[now]);
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
        char op;
        int x,y;
        cin>>op>>x>>y;
        if(op=='q')
        {
            if(findpar(x)==findpar(y))
                cout<<"yes\n";
            else
                cout<<"no\n";
        }
        else
        {
            par[findpar(x)]=findpar(y);
        }
    }
    return 0;
}