#include <bits/stdc++.h>
using namespace std;
struct dna
{
    int val;
    dna *next = NULL;
    dna *prev = NULL;
};
int dir = 1;
dna test[100100];
map<pair<int, int>, int> rev;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        int ind;
        cin >> ind;
        int start = cnt;
        test[cnt].val = cnt;
        cnt++;
        ind--;
        while (ind)
        {
            test[cnt].val = cnt;
            test[cnt].prev = &test[cnt - 1];
            test[cnt - 1].next = &test[cnt];
            cnt++;
            ind--;
        }
    }
    dna *now = &test[1];
    while (q--)
    {
        char op;
        cin >> op;
        if (op == 'F')
        {
            if (dir == 1 && now->next != NULL)
            {
                if (rev[make_pair(now->val, now->next->val)])
                    dir *= -1;
                now = now->next;
            }
            else if (dir == -1 && now->prev != NULL)
            {
                if (rev[make_pair(now->val, now->prev->val)])
                    dir *= -1;
                now = now->prev;
            }
        }
        if (op == 'B')
        {
            if (dir == 1 && now->prev != NULL)
            {
                if (rev[make_pair(now->val, now->prev->val)])
                    dir *= -1;
                now = now->prev;
            }
            else if (dir == -1 && now->next != NULL)
            {
                if (rev[make_pair(now->val, now->next->val)])
                    dir *= -1;
                now = now->next;
            }
        }
        if (op == 'C')
        {
            int ind;
            cin >> ind;
            if (dir == 1)
            {
                if(now->next!=NULL)
                {
                    if(rev[make_pair(now->val,now->next->val)])
                        now->next->next = NULL;
                    else
                        now->next->prev = NULL;
                }
                now->next = &test[ind];
                if (test[ind].prev == NULL)
                    test[ind].prev = now;
                else
                {
                    test[ind].next = now;
                    rev[make_pair(ind, now->val)] = 1;
                    rev[make_pair(now->val, ind)] = 1;
                }
            }
            else
            {
                if(now->prev != NULL)
                {
                    if(rev[make_pair(now->val,now->prev->val)])
                        now->prev->prev = NULL;
                    else
                        now->prev->next = NULL;
                }
                now->prev = &test[ind];
                if (test[ind].next == NULL)
                    test[ind].next = now;
                else
                {
                    test[ind].prev = now;
                    rev[make_pair(ind, now->val)] = 1;
                    rev[make_pair(now->val, ind)] = 1;
                }
            }
            if (dir == 1 && now->next != NULL)
            {
                if (rev[make_pair(now->val, now->next->val)])
                    dir *= -1;
                now = now->next;
            }
            else if (dir == -1 && now->prev != NULL)
            {
                if (rev[make_pair(now->val, now->prev->val)])
                    dir *= -1;
                now = now->prev;
            }
        }
        cout<<now->val<<'\n';
    }
    return 0;
}