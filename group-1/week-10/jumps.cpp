#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 1e9;

int a[MAXN], dp[MAXN][2];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][0] = dp[i][1] = -INF;
    }

    int ans = -INF;
    dp[1][0] = dp[1][1] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = a[i] + max(dp[i - 1][0], dp[i - 1][1]);
        if (i == 2) dp[i][1] = -INF;
        else dp[i][1] = a[i] + dp[i - 2][0];

        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << endl;
    return 0;
}