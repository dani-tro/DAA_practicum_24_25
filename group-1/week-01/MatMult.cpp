#include <bits/stdc++.h>

using namespace std;
const int maxx = 25;
long long A[maxx][maxx], B[maxx][maxx], C[maxx][maxx];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, i, j, t;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            cin >> A[i][j];
    
    for(i = 1; i <= m; i++)
        for(j = 1; j <= k; j++)
            cin >> B[i][j];
    
    for(i = 1; i <= n; i++)
        for(j = 1; j <= k; j++)
            {
                // Calculating C[i][j];
                for(t = 1; t <= m; t++)
                    C[i][j] = C[i][j] + A[i][t]*B[t][j];
            }
    
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= k; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}