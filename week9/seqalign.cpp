#include<bits/stdc++.h>
using namespace std;
char s[303];
char t[303];
int mic[303][303];
int seq(int i,int j)
{
    if(!i)
        return j;
    if(!j)
        return i;
    if(mic[i][j]!=-1)
        return mic[i][j];
    int minn = 1e9;
    if(s[i]==t[j])
        minn = min(minn,seq(i-1,j-1));
    else
    {
        minn = min(minn,seq(i-1,j-1)+1);
        minn = min(minn,seq(i-1,j)+1);
        minn = min(minn,seq(i,j-1)+1);
    }
    return mic[i][j]=minn;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s+1;
    cin>>t+1;
    int n = strlen(s+1);
    int m = strlen(t+1);
    for(int i = 0;i < 303; i++)
    {
        for(int j = 0; j < 303; j++)
        {
            mic[i][j]=-1;
        }
    }
    cout<<seq(n,m);
    return 0;
}