#include<bits/stdc++.h>
using namespace std;
struct necklace
{
    int val;
    necklace* next=NULL;
};
int last[300100];
int findst[300100];
necklace test[300100];
int findlast(int now)
{
    if(last[now] == now)    return now;
    return last[now] = findlast(last[now]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        last[i]=i;
        test[i].val=i;
    }
    for(int i = 0; i < n-1; i++)
    {
        int s,t;
        cin>>s>>t;
        findst[s]++;
        last[s] = findlast(s);
        test[last[s]    ].next=test[t].next;
        test[t].next=&(test[s]);
        if(last[t]==t)
        {
           last[t]=last[s];
        }
        //cout<<"\n\n\n\n"<<i<<'\n';
        // for(int i = 1; i <= n; i++)
        // {
        //     cout<<"last[" << i <<"] = "<<last[i]<<'\n';
        // }
    }
    int st;
    for(int i = 1; i <= n; i++)
    {
        if(!findst[i])
            st=i;
    }
    necklace* head = &test[st];
    while(head!=NULL)
    {
        cout<<head->val<<' ';
        head = head->next;
    }
    return 0;
}