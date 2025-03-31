#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

struct Event {
    int x;
    int type;
    int idx;
};

bool cmp(Event a, Event b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.type > b.type;
}

vector <Event> events;
int ans[MAXN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        events.push_back({a, 1, 0});
        events.push_back({b, -1, 0});
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        events.push_back({x, 0, i});
    }
    sort(events.begin(), events.end(), cmp);

    int cnt = 0;
    for (auto e : events) {
        if (e.type == 0) {
            ans[e.idx] = cnt;
        } else {
            cnt += e.type;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
/*
3 4
2 5
7 3
5 10
4 11 5 8
*/