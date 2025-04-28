#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 10;
const long long INF = 1e15;

long long dist[MAXN][MAXN];

void floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                dist[x][y] = min(dist[x][y], dist[x][k] + dist[k][y]);
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    floyd(n);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] >= INF) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }
}