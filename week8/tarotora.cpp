#include <bits/stdc++.h>
using namespace std;
int a[1010], b[1010];
int mic[220][1010];
int ans[220][1010][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        memset(mic, -1, sizeof(mic));
        mic[110][0] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < 220; i++)
            {
                if (mic[i][j] != -1)
                {
                    // cout<<"i:"<<i-110<<" j:"<<j<<" mic:"<<mic[i][j]<<endl;
                    if (i > 110 - k)
                    {
                        if (mic[i - 1][j + 1] == -1)
                        {
                            mic[i - 1][j + 1] = mic[i][j] + a[j];
                            ans[i - 1][j + 1][0] = ans[i][j][0] + a[j];
                            ans[i - 1][j + 1][1] = ans[i][j][1];
                        }
                        else if (mic[i - 1][j + 1] > mic[i][j] + a[j])
                        {
                            mic[i - 1][j + 1] = mic[i][j] + a[j];
                            ans[i - 1][j + 1][0] = ans[i][j][0] + a[j];
                            ans[i - 1][j + 1][1] = ans[i][j][1];
                        }
                    }
                    if (i < 110 + k)
                    {
                        if (mic[i + 1][j + 1] == -1)
                        {
                            mic[i + 1][j + 1] = mic[i][j] + b[j];
                            ans[i + 1][j + 1][0] = ans[i][j][0];
                            ans[i + 1][j + 1][1] = ans[i][j][1] + b[j];
                        }
                        else if (mic[i + 1][j + 1] > mic[i][j] + b[j])
                        {
                            mic[i + 1][j + 1] = mic[i][j] + b[j];
                            ans[i + 1][j + 1][0] = ans[i][j][0];
                            ans[i + 1][j + 1][1] = ans[i][j][1] + b[j];
                        }
                    }
                }
            }
        }
        int answ = 2e9;
        int ansa, ansb;
        for (int i = 0; i < 220; i++)
        {
            if (mic[i][n] != -1)
            {
                if (answ > mic[i][n])
                {
                    answ = mic[i][n];
                    ansa = ans[i][n][0];
                    ansb = ans[i][n][1];
                }
            }
        }
        cout << answ<< endl;
    }
    return 0;
}