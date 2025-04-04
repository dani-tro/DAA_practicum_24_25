#include <bits/stdc++.h>
using namespace std;

//unsigned l[100005];
//unsigned t[100005];
long n, k;

struct room {
    unsigned l, t;

    bool operator<(const room& other) const {
        return min(l, t) < min(other.l, other.t);
    }
};

priority_queue<room> rooms;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;

    for (long i = 0; i < n; ++i) {
        room r;
        cin >> r.l >> r.t;
        rooms.push(r);
    }

    long result = 0;
    for (long i = 0; i < k; ++i) {
        room r = rooms.top();
        rooms.pop();
        result += min(r.l, r.t);
        r.l -= min(r.l, r.t);
        rooms.push(r);
    }

    cout << result;
    return 0;
}