#include <iostream>
#include <algorithm>

using namespace std;
using llong = long long;

int const MAX = 1e5;

struct water {
    llong cont, tube;
    
    bool operator<(water const& other) const {
        return tube > other.tube || (tube == other.tube && cont > other.cont);
    }
};

water a[MAX+10];

bool check(llong spilled, llong k) {
    llong maxspill = 0, curspill = 0, i = 0;
    while (k) {
        if (a[i].cont <= curspill) {
            maxspill += curspill;
            curspill = 0;
            i++;
        }
        else {
            curspill += min(a[i].cont-curspill,a[i].tube);
            k--;
        }
    }

    maxspill += curspill;
    return maxspill >= spilled;
}

int main() {

    llong n, k;
    cin >> n >> k;
    for (llong i = 0; i < n; ++i) cin >> a[i].cont >> a[i].tube;

    sort(a,a+n);

    llong l = 0, r = 1e14, best = 0;
    while (l<r) {
        llong mid = (l+r)/2;
        if (check(mid,k)) {
            best = mid;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }

    cout << l;

    return 0;
}