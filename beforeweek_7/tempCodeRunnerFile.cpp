#include<bits/stdc++.h>
using namespace std;
int visited[1010];
int tree[1010][2];
struct player
{
    int x,y,layer;
};

queue<player> q;
int main()
{
    int n,r;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>r;
    tree[0][0]=0;tree[0][1]=0;
    for(int i = 1; i <= n; i++)
    {
            visited[i]=-1;
        cin>>tree[i][0]>>tree[i][1];
    }
    tree[n+1][0]=100;tree[n+1][1]=100;
    visited[n+1]=-1;
    q.push({0,0,0});
    while(!q.empty())
    {
        player now = q.front();
        q.pop();
        for(int i = 1; i <= n+1; i++)
        {
            if(visited[i]==-1&&(now.x-tree[i][0])*(now.x-tree[i][0])+(now.y-tree[i][1])*(now.y-tree[i][1])<=r*r)
            {
                visited[i]=now.layer+1;
                q.push({tree[i][0],tree[i][1],now.layer+1});
            }
        }
    }
    cout<<visited[n+1];
    return 0;
}