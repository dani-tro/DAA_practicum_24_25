#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const int MAXN = 1e6 + 10;

long long dp[MAXN];
bool mem[MAXN];

long long calc(int n) {
    if (n < 0) return 0;
    if (n <= 1) return dp[n] = 1;

    if (mem[n]) return dp[n];
    mem[n] = true;
    
    dp[n] = 0;
    for (int i = 1; i <= 6; i++) {
        dp[n] = (dp[n] + calc(n - i)) % mod;
    }
    return dp[n];
}
int main () {
    int n;
    cin >> n;
    cout << calc(n) << endl;
}