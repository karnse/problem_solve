#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int k = 1;
    int i = 1;
    int count=0;
    int m = 1;
    while(i<n)
    {
        m=0;
        while(m<k)
        {
            count++;
            m+=1;
        }
        k*=2;
        i+=k;
    }
    cout<<count<<' ' << m;
    return 0;
}