#include<bits/stdc++.h>
using namespace std;
map<int,int> mapp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int maxx=0;
    for(int i = 1; i <= n; i++)
    {
        int ind;
        cin>>ind;
        int ro=0;
        if(ind<i)
            ro=n-i+ind;
        else
            ro=ind-i;
        mapp[ro]++;
        maxx=max(maxx,mapp[ro]);
    }
    cout<<maxx;
    return 0;
}