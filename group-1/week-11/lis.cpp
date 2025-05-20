#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN], dp[MAXN];
int len;

void change_dp(int x) {
    if (x > dp[len]) {
        dp[len + 1] = x;
        len++;
        return;
    }

    int l, r, mid;
    l = 0; r = len;
    while (l <= r) {
        mid = (l + r) / 2;
        if (dp[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    dp[l] = x;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    len = 1;
    dp[1] = a[0];
    for (int i = 1; i < n; i++) {
        change_dp(a[i]);
    }
    cout << len << endl;
}