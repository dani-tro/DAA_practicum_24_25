# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
const int MOD = 1e9+7;
int dp[maxn];
int main()
{

    int n;
    cin >> n;
    int i, j;
    dp[0] = 1;
    for(i = 1; i <= n; i++)
    {
        for (j = 1; j <= 6; j++)
        {
            if (i - j < 0) break;
            dp[i] = (dp[i] + dp[i-j])%MOD;
        }
    }
    cout << dp[n] << endl;
}