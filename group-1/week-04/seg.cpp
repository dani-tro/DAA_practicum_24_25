#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Event {
    int x;
    int type;
};

bool cmp(Event a, Event b) {
    if (a.x != b.x) return a.x < b.x;
    return a.type < b.type;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector <Event> events(2 * n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events[2 * i] = {a, 1};
        events[2 * i + 1] = {b, -1};
    }
    sort(events.begin(), events.end(), cmp);

    int open, ptr, begX;
    open = ptr = 0;
    int cnt, maxLen;
    maxLen = cnt = 0;
    while (ptr < 2 * n) {
        int curX = events[ptr].x;
        if (open == 0) {
            begX = curX;
        }
        while (ptr < 2 * n && events[ptr].x == curX) {
            open += events[ptr].type;
            ptr++;
        }
        if (open == 0) {
            maxLen = max(maxLen, curX - begX);
            cnt++;
        }
    }
    cout << cnt << ' ' << maxLen << endl;
    return 0;
}