#include <bits/stdc++.h>
using namespace std;
char table[41][41];
int mic[41][41];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int cost[4] = {1, 1, 0, 5};
priority_queue<pair<int, pair<int, int> > > pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> table[i][j];
            mic[i][j] = 1e9;
        }
    }
    pq.push(make_pair(0, make_pair(h, 1)));
    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int wi = -pq.top().first;
        pq.pop();
        if (x == 1 && y == w)
        {
            cout << wi;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (x + d[i][0] >= 1 && x + d[i][0] <= h && y + d[i][1] >= 1 && y + d[i][1] <= w && table[x + d[i][0]][y + d[i][1]] == '.')
            {
                if (mic[x + d[i][0]][y + d[i][1]] > wi + cost[i])
                {
                    mic[x + d[i][0]][y + d[i][1]] = wi + cost[i];
                    pq.push(make_pair(-(wi + cost[i]), make_pair(x + d[i][0], y + d[i][1])));
                }
            }
        }
    }
    return 0;
}