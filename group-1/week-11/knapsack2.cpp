#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 10;
const int MAXV = 1e5 + 10;
const int INF = 1e9 + 10;

int w[MAXN];
int v[MAXN], dp[MAXN][MAXV];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, W;
    int maxV = 0;
    cin >> n >> W;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        maxV += v[i];
    }

    for (int i = 1; i <= maxV; i++) dp[0][i] = INF;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxV; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }

    int ans = 0;
    for (int j = maxV; j >= 0; j--) {
        if (dp[n][j] <= W) {
            ans = j;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}