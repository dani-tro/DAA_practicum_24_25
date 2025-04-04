#include <bits/stdc++.h>
using namespace std;

pair<unsigned long long, unsigned long long> inter[100005];
long n, m;

bool check(unsigned long long d) {
    long coins = n, x = 0, forbidden = -1;

    for (long i = 0; i < m; ++i) {
        if (inter[i].first > forbidden + 1) {
            x = inter[i].first;
        } else {
            x = forbidden + 1;
        }

        while (x <= inter[i].second) {
            --coins;

            if (coins == 0) {
                return true;
            }

            forbidden = x + d - 1;
            x = forbidden + 1;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    unsigned long long minL, maxR;

    for (long i = 0; i < m; ++i) {
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

    unsigned long long left = 1, right = (maxR - minL + 1) / n + 10, mid;
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