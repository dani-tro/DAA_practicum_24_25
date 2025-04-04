#include <bits/stdc++.h>
using namespace std;

unsigned x[200005];
long n;

bool check(long k) {
    for(long i = 0; i < n - k + 1; ++i) {
        if (x[i] + x[i + 1] > x[i + k - 1]) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for (long i = 0; i < n; ++i) {
        cin >> x[i];
    }

    sort(x, x + n);
    long left = 2, right = n, mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (check(mid)) {
            left = mid;

            if (left + 1 == right) {
                break;
            }
        } else {
            right = mid - 1;
        }
    }

    cout << (check(right) ? right : left);
    return 0;
}