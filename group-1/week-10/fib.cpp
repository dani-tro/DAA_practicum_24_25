#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const int MAXN = 2e3 + 10;

long long f[MAXN];
bool mem[MAXN];

long long fib(int n) {
    if (n <= 1) return f[n] = 1;
    if (mem[n]) return f[n];
    mem[n] = true;
    return f[n] = (fib(n - 1) + fib(n - 2)) % mod;
}
int main () {
    int n;
    cin >> n;
    cout << fib(n) << endl;
}