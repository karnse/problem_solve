#include<bits/stdc++.h>
#include"probelib.h"
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = probe_init();
    int l = 0;
    int r = n-1;
    while(l<r)
    {
        int mid = (l+r)/2; 
        if(probe_check(0,mid))
            r=mid;
        else
            l=mid+1;
    }
    int ll = l;
    probe_answer(ll);
    return 0;
}