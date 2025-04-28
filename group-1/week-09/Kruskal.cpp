#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXM = 2e5 + 10;

int par[MAXN], sz[MAXN];

int added_edges;

struct Edge {
    int u;
    int v;
    long long w;

    friend bool operator<(Edge a, Edge b) {
        return a.w < b.w;
    }
};

Edge e[MAXM];
long long sum;

int find_root(int x) {
    if (par[x] == x) return x;
    return par[x] = find_root(par[x]);
}

void connect(int a, int b, long long w) {
    int ra, rb;
    ra = find_root(a);
    rb = find_root(b);

    if (ra == rb) return;

    sum += w;
    added_edges++;

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
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e+m);

    for (int i = 0; i < m; i++) {
        connect(e[i].u, e[i].v, e[i].w);
    }
    if (added_edges != n - 1) cout << "IMPOSSIBLE\n";
    else cout << sum << endl;

    return 0;
}