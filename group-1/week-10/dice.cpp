#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 2;
const int MAXS = 6e3 + 2;
const long long mod = 1e9 + 7;

long long dp[MAXN][MAXS];
bool mem[MAXN][MAXS];

long long func(int n, int s) {
    if (s < 0) return 0;
    if (n == 0 && s == 0) return 1;
    if (n == 0 && s > 0) return 0;

    if (mem[n][s]) return dp[n][s];
    
    mem[n][s] = true;
    dp[n][s] = 0;
    for (int i = 1; i <= 6; i++) {
        dp[n][s] = (dp[n][s] + func(n - 1, s - i)) % mod;
    }
    return dp[n][s];
}

int main () {
    int n, s;
    cin >> n >> s;
    cout << func(n, s) << endl;
    return 0;
}