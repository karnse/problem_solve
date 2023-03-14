#include<bits/stdc++.h>
using namespace std;
char s[1001],t[1001];
stack<char> ans;
int mic[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s+1;
    cin >> t+1;
    int n = strlen(s+1);
    int m = strlen(t+1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            mic[i][j] = max(mic[i-1][j],mic[i][j-1]);
            if(s[i]==t[j])
                mic[i][j] = max(mic[i][j],mic[i-1][j-1]+1);
        }
    }
    cout<<mic[n][m]<<'\n';
    int ii = n;
    int jj = m;
    while(ii>0&&jj>0)
    {
        if(s[ii]==t[jj])
        {
            ans.push(s[ii]);
            ii--;
            jj--;
        }
        else
        {
            if(mic[ii-1][jj]>mic[ii][jj-1])
                ii--;
            else
                jj--;
        }
    }
    while(!ans.empty())
    {
        cout<<ans.top();
        ans.pop();
    }

    return 0;
}