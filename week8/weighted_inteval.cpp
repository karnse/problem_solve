#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
pair<pair<int,int>,int> in[100100];
int mic[100100];
int fi[100100];
int fo[100100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> in[i].first.first >> in[i].first.second >> in[i].second;
        fi[i]=in[i].first.second;
    }
    for(int i = 1; i <= n; i++)
    {
        int ind = -1;
        int maxind = 0;
        for(int j = 1; j < i; j++)
        {
            if(fi[j]<=in[i].first.first)
            {
                if(mic[j]>maxind)
                {
                    maxind = mic[j];
                    ind = j;
                }
            }
        }
        mic[i] = maxind+in[i].second;
        fo[i] = ind;
    }
    int indans=0;
    for(int i = 1; i <= n; i++)
    {
        if(mic[i]>mic[indans])
        {
            indans = i;
        }
    }
    cout << mic[indans] << '\n';
    while(indans>0)
    {
        ans.push_back(indans);
        indans = fo[indans];
    }
    cout << ans.size() << '\n';
    for(int i = ans.size()-1; i >= 0; i--)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}