#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 1e9;

int dp[MAXN], b[MAXN];
bool mem[MAXN];

int calc(int n) {
    if (n == 1) return b[1];
    if (n == 2) return max(b[1], b[2]);

    if (mem[n]) return dp[n];
    mem[n] = true;
    
    dp[n] = max(calc(n - 1), calc(n - 2) + b[n]);
    return dp[n];
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    cout << calc(n) << endl;
}