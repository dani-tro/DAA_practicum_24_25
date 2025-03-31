#include <bits/stdc++.h>
using namespace std;

#define llong long long

const llong INF = 1e18;

llong n, f;
bool check(llong x) {
    // (2 * f + x - 1) * x / 2 >= n
    // (2 * f + x - 1) >= 2 * n / x
    return (2 * f + x - 1) > 2 * n / x || ((2 * f + x - 1) == 2 * n / x && (2 * n) % x == 0);
}
int main () {
    cin >> n >> f;
    llong l, r, mid;
    l = 1; r = INF;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}