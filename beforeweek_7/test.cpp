#include<bits/stdc++.h>
using namespace std;
int table[3][3];
void edi(int matrix[3][3])
{
    matrix[0][0]=1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    edi(table);
    for(int i =0 ; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ",table[i][j]);
        }
        cout<<endl;
    }
    return 0;
}