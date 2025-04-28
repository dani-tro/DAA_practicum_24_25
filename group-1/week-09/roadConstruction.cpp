#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int par[MAXN], sz[MAXN];
int comp, maxSize;

int find_root(int x) {
    if (par[x] == x) return x;
    return par[x] = find_root(par[x]);
}

void connect(int a, int b) {
    int ra, rb;
    ra = find_root(a);
    rb = find_root(b);

    if (ra == rb) return;

    comp--;

    if (sz[ra] > sz[rb]) {
        par[rb] = ra;
        sz[ra] += sz[rb];
        maxSize = max(maxSize, sz[ra]);
    } else {
        par[ra] = rb;
        sz[rb] += sz[ra];
        maxSize = max(maxSize, sz[rb]);
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
    comp = n;
    maxSize = 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        connect(a, b);
        cout << comp << ' ' << maxSize << endl;
    }
    return 0;
}
