#include<bits/stdc++.h>
using namespace std;
char x[100100];
char old[100100];
vector<int> g[30];
int indegee[30];
queue<int> q;
map<char,int> mapp;
int main()
{
    int op = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1)
    {
        cin>>x;
        if(x[0]!='#')
        {
            for(int i = 0; i < strlen(x); i++)
            {
                mapp[x[i]]++;
            }
            if(op)
            {
                int wi = min(strlen(x),strlen(old));
                for(int i = 0; i < wi; i++)
                {
                    if(x[i]!=old[i])
                    {
                        g[old[i]-'A'].push_back(x[i]-'A');
                        indegee[x[i]-'A']++;
                        break;
                    }
                }
            }
            strcpy(old,x);
        }
        else
        {
            break;
        }
        op=1;
    }
    for(auto nod: mapp)
    {
        // cout<<nod.first<<'\n';
        if(!indegee[nod.first-'A'])
        {
            q.push(nod.first-'A');
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        printf("%c",u+'A');
        q.pop();
        for(auto ne: g[u])
        {
            if(--indegee[ne]==0)
            {
                q.push(ne);
            }
        }
    }
    return 0;
}