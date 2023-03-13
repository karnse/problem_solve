#include<bits/stdc++.h>
using namespace std;
char table[40][40];
queue<pair<int,int> > q1,q2;
int visited1[40][40];
int visited2[40][40];
int d[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>>table[i][j];
            if(table[i][j]=='*')
            {
                visited1[i][j]=1;
                q1.push(make_pair(i,j));
            }
            if(table[i][j]=='$')
            {
                visited2[i][j]=1;
                q2.push(make_pair(i,j));
            }
        }
    }
    pair<int,int> now;
    while(!q1.empty())
    {
        now = q1.front();
        q1.pop();
        for(int i = 0 ; i < 4; i++)
        {
            int nx = now.first+d[i][0];
            int ny = now.second+d[i][1];
            if(nx&&ny&&nx<=n&&ny<=m&&table[nx][ny]!='#'&&!visited1[nx][ny])
            {
                visited1[nx][ny]=1;
                q1.push(make_pair(nx,ny));
            }
        }
    }
    while(!q2.empty())
    {
        now = q2.front();
        q2.pop();
        for(int i = 0 ; i < 4; i++)
        {
            int nx = now.first+d[i][0];
            int ny = now.second+d[i][1];
            if(nx&&ny&&nx<=n&&ny<=m&&table[nx][ny]!='#'&&!visited2[nx][ny])
            {
                visited2[nx][ny]=1;
                q2.push(make_pair(nx,ny));
            }
        }
    }
    int ans2=0;
    int ans1=0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int ind = visited1[i][j]+visited2[i][j];
            if(ind==1)
                ans1++;
            if(ind==2)
                ans2++;
        }
    }
    cout<<ans2<<' '<<ans1;
    return 0;
}