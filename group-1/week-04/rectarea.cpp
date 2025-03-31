#include <bits/stdc++.h>
using namespace std;

struct Event {
    int x;
    int y1;
    int y2;
    int type;
};

bool cmp(Event a, Event b) {
    return a.x < b.x;
}

const int MAXY = 2e4 + 1;
const int offset = 1e4;
vector <Event> events;

int cnt[MAXY];

int get_cnt() {
    int res = 0;
    for (int y = 0; y < MAXY; y++) {
        if (cnt[y] > 0) res++;
    }
    return res;
}

void update(int y1, int y2, int type) {
    for (int i = y1; i < y2; i++) {
        cnt[i] += type;
    }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += offset;
        y1 += offset;
        x2 += offset;
        y2 += offset;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});
    }
    sort(events.begin(), events.end(), cmp);

    int lastX = 0, ans = 0;
    for (auto e : events) {
        ans += (e.x - lastX) * get_cnt();
        lastX = e.x;
        update(e.y1, e.y2, e.type);
    }
    cout << ans << endl;
    return 0;
}
/*
2
1 1 3 3
2 2 4 4

3
1 1 3 2
1 3 3 4
2 1 4 4
*/