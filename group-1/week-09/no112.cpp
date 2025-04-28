#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int par[MAXN], sz[MAXN];

int find_root(int x) {
    if (par[x] == x) return x;
    return par[x] = find_root(par[x]);
}

void connect(int a, int b) {
    int ra, rb;
    ra = find_root(a);
    rb = find_root(b);

    if (ra == rb) return;

    if (sz[ra] > sz[rb]) {
        par[rb] = ra;
        sz[ra] += sz[rb];
    } else {
        par[ra] = rb;
        sz[rb] += sz[ra];
    }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        connect(a, b);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            cout << (find_root(a) == find_root(b));
        } else {
            connect(a, b);
        }
    }
    return 0;
}

/*
9 8
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
6
1 1 8
1 6 2
2 7 1
1 4 7
2 2 3
1 4 7
*/