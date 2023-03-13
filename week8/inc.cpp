#include<bits/stdc++.h>
using namespace std;
int arr[100100];
int lis[100100];
vector<int> vlis[100100];
stack<int> st;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    int indans = 0;
    for(int i = 1; i <= n; i++)
    {
        int ind = lower_bound(lis,lis+indans,arr[i])-lis;
        lis[ind] = arr[i];
        vlis[ind].push_back(arr[i]);
        if(ind==indans)
        {
            indans++;
        }
    }
    cout << indans << '\n';
    int now = 1e9;
    for(int i = indans-1; i >= 0; i--)
    {
        for(int j = 0; j < vlis[i].size(); j++)
        {
            if(vlis[i][j]<now)
            {
                st.push(vlis[i][j]);
                break;
            }
        }
    }
    while(!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}