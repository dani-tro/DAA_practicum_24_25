#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 10;

struct Singer {
    int beg;
    int sec;
};

Singer singers[MAXN];

int studio[MAXN], n;

bool cmp(Singer a, Singer b) {
    if (a.beg != b.beg) return a.beg < b.beg;
    return a.sec > b.sec;
}

int find_studio(int t) {
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        if (studio[i] <= t) return i;
        if (studio[i] < studio[idx]) idx = i;
    }
    return idx;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> singers[i].beg >> singers[i].sec;
    }

    sort(singers, singers + m, cmp);
    for (int i = 1; i <= n; i++) {
        studio[i] = 0;
    }

    int ansTime, ansIdx = 0;
    ansTime = 0;
    for (int i = 0; i < m; i++) {
        int idx = find_studio(singers[i].beg);
        studio[idx] = max(singers[i].beg, studio[idx]) + singers[i].sec;

        if (studio[idx] > ansTime || (studio[idx] == ansTime && idx > ansIdx)) {
            ansTime = studio[idx];
            ansIdx = idx;
        }
    }
    cout << ansTime << ' ' << ansIdx << endl;
    return 0;
}
/*

*/