#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int dp[MAXN], h[MAXN];
bool mem[MAXN];

int calc(int n) {
    if (n == 1) return 0;
    if (n == 2) return abs(h[2] - h[1]);

    if (mem[n]) return dp[n];
    mem[n] = true;
    
    dp[n] = min(calc(n - 1) + abs(h[n] - h[n - 1]),
                calc(n - 2) + abs(h[n] - h[n - 2]));
    return dp[n];
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    cout << calc(n) << endl;
}