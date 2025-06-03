#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
const int MAXK = 1e3 + 10;
const long long INF = 1e18;

long long a[MAXN], dpL[MAXN], dpR[MAXN], maxR[MAXN];
int mov[MAXK];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) cin >> mov[i];

    dpL[0] = a[0];
    for (int i = 1; i < n; i++) {
        dpL[i] = -INF;
        for (int j = 0; j < k; j++) {
            if (i - mov[j] < 0) continue;
            dpL[i] = max(dpL[i], dpL[i - mov[j]] + a[i]);
        }
    }

    dpR[n - 1] = maxR[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        dpR[i] = -INF;
        for (int j = 0; j < k; j++) {
            if (i + mov[j] >= n) continue;
            dpR[i] = max(dpR[i], dpR[i + mov[j]] + a[i]);
        }
        maxR[i] = max(maxR[i + 1], dpR[i]);
    }

    long long ans = -INF;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, dpL[i] + maxR[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
/*
9 2
3 2 6 6 0 2 4 5 5
3 2
*/