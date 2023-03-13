#include<bits/stdc++.h>
using namespace std;
int ba[100100];
int mic[100100];
int re(int n)
{
    if(mic[n])  return mic[n];
    if(n<3) return 0;
    return mic[n] = max(re(n-1),ba[n]+re(n-3));
}
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
    cout<<re(n);
    return 0;
}