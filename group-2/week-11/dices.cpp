# include <bits/stdc++.h>
using namespace std;
int dp[1005][6005];
const int MOD = 1e9+7;
int main()
{
    int n, s;
    cin >> n >> s;
    int i, j;
    dp[0][0] = 1;
    for (i  = 1; i <= n; i++)
    {
        for(j = 1; j <= s; j++)
        {
            for(int k = 1; k <= 6; k++)
            {
                if(j - k < 0) break;
                dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
            }
        }
    }

    cout << dp[n][s] << endl;
}