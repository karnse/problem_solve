#include<bits/stdc++.h>
using namespace std;
int ba[100100];
int now[100100];
int mic[100100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>ba[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(i>=3)
        {
            now[i] = ba[i]+mic[i-3];
        }
        mic[i] = max(mic[i-1],now[i]);
    }
    // for(int i = 1; i <=n; i++)
    // {
    //     cout<<mic[i]<<' ';
    // }
    // cout<<endl;
    cout<<mic[n];
    return 0;
}