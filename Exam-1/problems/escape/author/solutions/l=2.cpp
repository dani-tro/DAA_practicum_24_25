#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e5+10;

priority_queue < int > remainders;

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

void solve() {

    // cout << "solve\n";
    sort(wall+1, wall+1+n, greater < sector >());

    long long ans = 0, ones = 0;

    for (int i = 1 ; i <= n && k > 0 ; ++i) {

        ans += wall[i].l*min((long long)wall[i].h/wall[i].l, k);
        k -= min((long long)wall[i].h/wall[i].l, k);
        ones += wall[i].h % wall[i].l;

    }

    ans += min(k, ones);

    cout << ans << '\n';

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