#include<bits/stdc++.h>
using namespace std;
long long arr[100100];
long long tmp[100100];
long long ans;
void merge_sort(long long l,long long r)
{
    if(l == r)
    {
        return;
    }
    long long mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    long long i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
            ans += mid - i + 1;
        }
    }
    while(i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while(j <= r)
    {
        tmp[k++] = arr[j++];
    }
    for(long long i = l; i <= r; i++)
    {
        arr[i] = tmp[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    merge_sort(1, n);
    cout<<ans;
    return 0;
}