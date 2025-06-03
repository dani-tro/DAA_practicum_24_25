#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 10;
const long long INF = 1e18;
long long a[MAXN], pref[MAXN];
long long dp[MAXN][MAXN];
bool mem[MAXN][MAXN];

long long find_ans(int l, int r) {
    if (l == r) return 0;

    if (mem[l][r]) return dp[l][r];
    mem[l][r] = true;

    dp[l][r] = INF;
    for (int k = l; k < r; k++) {
        dp[l][r] = min(dp[l][r], find_ans(l, k) + find_ans(k + 1, r));
    }
    dp[l][r] += pref[r] - pref[l - 1];
    return dp[l][r];
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    cout << find_ans(1, n) << endl;
}