#include <bits/stdc++.h>

using namespace std;

const int MAXX = 1e6 + 10;
const int MAXN = 1e2 + 10;
const int INF = 1e9;

int a[MAXN];
int dp[MAXX];
bool mem[MAXX];

int n;

int func(int s) {
    if (s < 0) return INF;
    if (s == 0) return 0;
    
    if (mem[s]) return dp[s];
    mem[s] = true;
    dp[s] = INF;
    for (int i = 0; i < n; i++) {
        dp[s] = min(dp[s], func(s - a[i]) + 1);
    }

    return dp[s];
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = func(x);
    if (res == INF) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}