#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10;

int a[MAXN], dp[MAXN];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int len = 1;
    dp[1] = a[0];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= len; j++) {
            if (a[i] > dp[j - 1] && a[i] < dp[j]) {
                dp[j] = a[i];
            }
        }
        if (a[i] > dp[len]) {
            dp[len + 1] = a[i];
            len++;
        }
    }

    cout << len << endl;
}