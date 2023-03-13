#include "traffic.h"
#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<pair<int, int>, pair<int, int> > ans[2];
int cnt = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    traffic_init(&n, &m);
    for (int i = 1; i <= n; i++)
    {
        int test1 = traffic_query(1, i, n, i);
        int test2 = traffic_query(i, 1, i, n);
        if (test1 == n)
        {
            int l = 1, r = n;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (traffic_query(1, i, mid, i) == mid)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ans[cnt++] = make_pair(make_pair(r - 1, i), make_pair(r, i));
            if (cnt == m)
                break;
        }
        if (test2 == n)
        {
            int l = 1, r = n;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (traffic_query(i, 1, i, mid) == mid)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ans[cnt++] = make_pair(make_pair(i, r - 1), make_pair(i, r));
            if (cnt == m)
                break;
        }
        if (test1 == n + 1)
        {
            int l = 1, r = n;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (traffic_query(1, i, mid, i) == mid + 1)
                {
                    r = mid;
                }
                else
                {
                    l = mid+1;
                }
            }
            ans[cnt++] = make_pair(make_pair(r - 1, i), make_pair(r, i));
            l = 1;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (traffic_query(1, i, mid, i) == mid)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ans[cnt++] = make_pair(make_pair(r - 1, i), make_pair(r, i));
            if (cnt == m)
                break;
        }
        if (test2 == n + 1)
        {
            int l = 1, r = n;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (traffic_query(i, 1, i, mid) == mid + 1)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ans[cnt++] = make_pair(make_pair(i, r - 1), make_pair(i, r));
            l = 1;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (traffic_query(i, 1, i, mid) == mid)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ans[cnt++] = make_pair(make_pair(i, r - 1), make_pair(i, r));
            if (cnt == m)
                break;
        }
    }
    traffic_report(ans[0].first.first, ans[0].first.second, ans[0].second.first, ans[0].second.second, ans[1].first.first, ans[1].first.second, ans[1].second.first, ans[1].second.second);
    return 0;
}