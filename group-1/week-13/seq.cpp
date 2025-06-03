#include <bits/stdc++.h>
using namespace std;

const int MAXN = 64;

long long dp[MAXN][MAXN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> k >> n;
    for (int p = 1; p <= k; p++) dp[1][p] = 1;

    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = 0;
            for (int p = 1; p <= j - 1; p++) dp[i][j] += dp[i - 1][p];
            if (i == n) ans += dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}