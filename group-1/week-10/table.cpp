#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;
const int INF = 1e9;

int a[MAXN][MAXN], dp[MAXN][MAXN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (j == 0) dp[i][j] = a[i][j];
        }
    }

    int ans = INF;
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            dp[i][j] = INF;
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j]);
            if (i < n - 1) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + a[i][j]);
            if (j == m - 1) ans = min(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}