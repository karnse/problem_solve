#include<bits/stdc++.h>
using namespace std;
char s[1001],t[1001];
stack<int> ans;
int mic[1001][1001];
int lcs(int i,int j)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s+1;
    cin >> t+1;
    int n = strlen(s+1);
    int m = strlen(t+1);
    cout<<lcs(n,m);
    return 0;
}