#include <bits/stdc++.h>
using namespace std;

double v1, v2;
double getDist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double f(double mid, double x1, double y1, double x2, double y2) {
    double res = getDist(x1, y1, mid, 0) / v1 + getDist(x2, y2, mid, 0) / v2;
    return res;
}
void solve() {
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2 >> v1 >> v2;
    double l, r, mid1, mid2;
    l = min(x1, x2);
    r = max(x1, x2);

    for (int i = 0; i < 128; i++) {
        mid1 = l + (r - l) / 3.0;
        mid2 = l + (r - l) * 2.0 / 3.0;

        if (f(mid1, x1, y1, x2, y2) >= f(mid2, x1, y1, x2, y2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }

    cout << fixed << setprecision(5) << f(l, x1, y1, x2, y2) << endl;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
    return 0;
}