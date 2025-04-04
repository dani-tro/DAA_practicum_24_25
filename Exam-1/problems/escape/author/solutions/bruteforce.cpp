#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e5+10;

struct sector {

    int h, l;
    sector(){}
    sector(istream &in) {

        in >> h >> l;

    }

    inline friend bool operator > (sector a, sector b) {

        return a.l > b.l;

    }

} wall[maxn];

int n;
long long k;

int brute(int ix, int sum) {

    if (sum == 0) return 0;
    if (ix == n) return min(sum*wall[ix].l, wall[ix].h);
    
    int ans = 0;
    for (int i = 0 ; i <= sum ; ++i) {
    
        ans = max(ans, brute(ix+1, sum-i) + min(wall[ix].l * i, wall[ix].h));
        if (wall[ix].l * i >= wall[ix].h) break;
    
    }

    return ans;

}

void solve() {

    cout << brute(1, k) << '\n';

}

void fast_io() {

    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

}

void read() {

    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++i)
        wall[i] = sector(cin);

}

int main () {

    fast_io();
    read();
    solve();

    return 0;

}