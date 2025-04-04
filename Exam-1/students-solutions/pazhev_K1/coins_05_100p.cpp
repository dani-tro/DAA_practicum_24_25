#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> inter[100005];
long long n, m;

bool check(long long d) {
    long long coins = n, x = 0;

    for (long i = 0; i < m; ++i) {
        if (inter[i].first > x) {
            x = inter[i].first;
        }

        while (x <= inter[i].second) {
            if (--coins == 0) {
                return true;
            }

            x += d;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    long long minL, maxR;

    for (long long i = 0; i < m; ++i) {
        cin >> inter[i].first >> inter[i].second;

        if (i == 0) {
            minL = inter[i].first;
            maxR = inter[i].second;
        } else {
            minL = min(minL, inter[i].first);
            maxR = max(maxR, inter[i].second);
        }
    }

    sort(inter, inter + m);

    long long left = 1, right = (maxR - minL + 1), mid;
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