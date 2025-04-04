#include <iostream>
#include <algorithm>

using namespace std;
using llong = long long;

llong const MAX = 2*1e6;

llong a[MAX+10];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    llong n;
    cin >> n;
    for (llong i = 0; i < n; ++i) cin >> a[i];

    sort(a,a+n);

    llong cnt = 2, maxcnt = 2, minsum = a[0]+a[1];
    llong i = 0, j = 2;
    while (i<n-1 && j<n) {
        if (minsum<=a[j]) {
            maxcnt = max(maxcnt,cnt);
            cnt = j-i;
            i++;
            minsum = a[i]+a[i+1];
        }
        else {
            cnt++;
        }
        j++;
    }

    maxcnt = max(maxcnt,cnt);

    cout << maxcnt;

    return 0;
}