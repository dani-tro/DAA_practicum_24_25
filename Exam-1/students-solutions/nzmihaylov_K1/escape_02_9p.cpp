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

bool check(llong spilled, llong k, llong n) {
    llong maxspill = 0, i = 0;
    for (llong i = 0; i < n && k > 0; ++i) {
        llong spill = a[i].cont / a[i].tube;
        maxspill += spill * a[i].tube;
        k-=spill;
    }

    for (llong i = 0; i < n && k > 0; ++i) {
        llong spill = a[i].cont % a[i].tube;
        maxspill += spill;
        k--;
    }

    return maxspill >= spilled;
}

int main() {

    llong n, k;
    cin >> n >> k;
    for (llong i = 0; i < n; ++i) cin >> a[i].cont >> a[i].tube;

    sort(a,a+n);

    llong l = 0, r = 1e12;
    while (l<r) {
        llong mid = (l+r)/2;
        if (check(mid,k,n)) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }

    cout << l;

    return 0;
}