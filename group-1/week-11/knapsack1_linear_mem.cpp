#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 10;
const int MAXW = 1e5 + 10;
const long long INF = 1e15;

int w[MAXN];
long long v[MAXN], dp[MAXW];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, W;
    cin >> n >> W;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    dp[0] = 0;
    for (int i = 1; i <= W; i++) dp[i] = -INF;

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= 0; j--) {
            if (j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            if (i == n) ans = max(ans, dp[j]);
        }
    }

    cout << ans << endl;
    return 0;
}