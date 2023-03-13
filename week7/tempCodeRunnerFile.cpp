#include<bits/stdc++.h>
using namespace std;
int arr[100100];
int tmp[100100];
void merge_sort(int l,int r)
{
    if(l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
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
    for(int i = l; i <= r; i++)
    {
        arr[i] = tmp[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n)
    {
        for(int i = 1; i <= n; i++)
        {
            cin>>arr[i];
        }
        merge_sort(1,n);
        for(int i = 1; i < n; i++)
        {
            cout<< arr[i] << " ";
        }
        cout<<arr[n]<<"\n";
        cin>>n;
    }
    return 0;
}