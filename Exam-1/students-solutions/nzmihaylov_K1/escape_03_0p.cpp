#include <iostream>
#include <algorithm>
#include <queue>

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
    //pairs of leftover water inside container + index to access the tube's capacity
    priority_queue<pair<llong,llong> > q;
    for (llong i = 0; i < n; ++i) {
        q.push({max((llong)0,a[i].cont-a[i].tube),i});
    } 

    //problematic
    llong maxspilled = max((llong)0,a[q.top().second].tube);
    while (--k > 0 && !q.empty()) {
        pair<llong,llong> top = q.top();
        q.pop();
        if (top.first+a[top.second].tube==a[top.second].cont) {
            maxspilled += a[top.second].tube;
            k--;
        }

        llong spill = min(top.first,a[top.second].tube);
        maxspilled += spill;
        top.first -= spill;
        if (top.first>0) q.push(top);
    }

    return maxspilled>=spilled;
}

int main() {

    llong n, k;
    cin >> n >> k;
    for (llong i = 0; i < n; ++i) cin >> a[i].cont >> a[i].tube;

    llong l = 0, r = 100, best = 0;
    while (l<r) {
        llong mid = (l+r)/2;
        if (check(mid,k,n)) {
            best = mid;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }

    cout << best;

    return 0;
}