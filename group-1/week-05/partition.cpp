#include <bits/stdc++.h>
using namespace std;

const double epsilon = 1e-6;
double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    return fabs((x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1)) / 2.0;
}

bool equalsTo(double a, double b) {
    return fabs(a - b) < epsilon;
}
int main () {
    double ax, ay, bx, by, cx, cy, px, py;
    ax = ay = cx = 0;
    cin >> cy >> bx >> by >> px >> py;

    if (equalsTo(area(ax, ay, bx, by, px, py), 0)) {
        swap(ax, cx);
        swap(ay, cy);
    }

    if (equalsTo(area(ax, ay, cx, cy, px, py), 0)) {
        swap(ax, bx);
        swap(ay, by);
    }
    // P lies on BC

    double apc = area(ax, ay, px, py, cx, cy);
    double abc = area(ax, ay, bx, by, cx, cy);
    if (apc * 2.0 < abc) {
        swap(bx, cx);
        swap(by, cy);
    }

    double l, r, mid;
    l = 0;
    r = 1;
    //while (r - l > epsilon)

    for (int i = 0; i < 128; i++) {
        mid = (l + r) / 2.0;
        double qx, qy;
        qx = ax + (cx - ax) * mid;
        qy = ay + (cy - ay) * mid;

        double pcq = area(px, py, cx, cy, qx, qy);

        if (2.0 * pcq >= abc) {
            l = mid;
        } else {
            r = mid;
        }
    }

    double qx, qy;
    qx = ax + (cx - ax) * l;
    qy = ay + (cy - ay) * r;

    cout << std::fixed << std::setprecision(6) << qx << ' ' << qy << endl;
    return 0;
}