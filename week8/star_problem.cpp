#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100];
int mic[3][100100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        mic[0][i] = max(mic[0][i-1],max(mic[2][i-1],mic[1][i-1]));
        mic[1][i] = max(mic[0][i-1],mic[2][i-1])+a[i];
        mic[2][i] = max(mic[0][i-1],mic[1][i-1])+b[i];
    }
    cout<<max(mic[0][n],max(mic[1][n],mic[2][n]));
    return 0;
}