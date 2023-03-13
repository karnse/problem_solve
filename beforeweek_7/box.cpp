#include<bits/stdc++.h>
using namespace std;
char table[50][50];
int visited[50][50];
int ans=0;
int n,m;
void print_table()
{
    for(int i = 0; i < n+2; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            cout<<visited[i][j];
        }
        cout<<'\n';
    }
}
void dfs(int si,int sj)
{
    // print_table();
    if(si==n-1)
        ans=1;
    if(ans)
        return;
    if(si&&!visited[si-1][sj]&&table[si-1][sj]!='#'&&!visited[si-1][sj+1]&&table[si-1][sj+1]!='#')
    {
        visited[si-1][sj]=1;
        visited[si-1][sj+1]=1;
        dfs(si-1,sj);
        visited[si-1][sj]=0;
        visited[si-1][sj+1]=0;
    }
    if(si<n&&!visited[si+2][sj]&&table[si+2][sj]!='#'&&!visited[si+2][sj+1]&&table[si+2][sj+1]!='#')
    {
        visited[si+2][sj]=1;
        visited[si+2][sj+1]=1;
        dfs(si+1,sj);
        visited[si+2][sj]=0;
        visited[si+2][sj+1]=0;
    }
    if(sj&&!visited[si][sj-1]&&table[si][sj-1]!='#'&&!visited[si+1][sj-1]&&table[si+1][sj-1]!='#')
    {
        visited[si][sj-1]=1;
        visited[si+1][sj-1]=1;
        dfs(si,sj-1);
        visited[si][sj-1]=0;
        visited[si+1][sj-1]=0;
    }
    if(sj<m-2&&!visited[si][sj+2]&&table[si][sj+2]!='#'&&!visited[si+1][sj+2]&&table[si+1][sj+2]!='#')
    {
        visited[si][sj+2]=1;
        visited[si+1][sj+2]=1;
        dfs(si,sj+1);
        visited[si][sj+2]=0;
        visited[si+1][sj+2]=0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %d %d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        scanf(" %s",table[i+2]);
    }
    visited[0][0]=1;
    visited[0][1]=1;
    visited[1][0]=1;
    visited[1][1]=1;
    dfs(0,0);
    if(ans)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}