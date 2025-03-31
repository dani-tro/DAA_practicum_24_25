#include <iostream>
#include <algorithm>
using namespace std;

#define llong long long

const llong INF = 1e18 + 10;
llong a, k, b, m, x;

bool check(llong mid) {
    llong res = mid * a - (mid / k) * a + mid * b - (mid / m) * b;
    return res >= x;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> k >> b >> m >> x;
    llong l, r, mid;
    l = 1; r = 2 * x / (a + b) + 3;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}