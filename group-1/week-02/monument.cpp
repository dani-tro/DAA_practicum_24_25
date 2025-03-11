#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;

int a[MAXN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ri = 0;
    long long ans = 0;
    for (int lef = 0; lef < n; lef++) {
        while (ri < n && a[ri] - a[lef] <= r) {
            ri++;
        }

        ans += (long long)(n - ri);
    }

    cout << ans << endl;
    return 0;
}