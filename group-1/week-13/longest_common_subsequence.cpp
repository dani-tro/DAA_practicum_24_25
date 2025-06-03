#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 10;

int dp[MAXN][MAXN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    string str1, str2;
    cin >> str1 >> str2;
    n = str1.size(); m = str2.size();

    dp[0][0] = (str1[0] == str2[0]);
    for (int i = 1; i < n; i++) dp[i][0] = max(dp[i - 1][0], (int)(str1[i] == str2[0]));
    for (int i = 1; i < m; i++) dp[0][i] = max(dp[0][i - 1], (int)(str1[0] == str2[i]));

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (str1[i] == str2[j]));
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}