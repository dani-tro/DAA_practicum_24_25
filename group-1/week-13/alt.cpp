#include <bits/stdc++.h>
using namespace std;

const int MAXN = 64;

long long dp[MAXN][MAXN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, m;
    cin >> k >> m >> n;
    for (int p = 1; p < m; p++) dp[1][p] = 1;

    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = 0;
            if (j + k < m) dp[i][j] += dp[i - 1][j + k];
            if (j - k > 0) dp[i][j] += dp[i - 1][j - k];
            if (i == n) ans += dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}