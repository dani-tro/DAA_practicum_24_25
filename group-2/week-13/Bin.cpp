# include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
long long dp[maxn][maxn];
int main()
{
    int k, n;
    cin >> k >> n;
    for(int i = 1; i <= k; i++)
        dp[i][1] = i;

    for(int i = 1; i <= k; i++)
    {
        for(int j = 2; j <= n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1]; 
        }
    }

    cout << dp[k][n] << endl;
}