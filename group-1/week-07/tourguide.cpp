#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

vector <pair <int, int> > v[MAXN];
int dist[MAXN];
int n;

void dijkstra(int start) {
    for (int i = 0; i <= n; i++) {
        dist[i] = -1;
    }

    priority_queue<pair <int, int> > q;
    dist[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        int x = q.top().second;
        if (dist[x] != -q.top().first) {
            q.pop();
            continue;
        }
        q.pop();

        for (auto i : v[x]) {
            if (dist[i.first] == -1 || dist[i.first] > dist[x] + i.second) {
                dist[i.first] = dist[x] + i.second;
                q.push({-dist[i.first], i.first});
            }
        }
    }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        v[n].push_back({a, 0});
    }
    dijkstra(n);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        cout << dist[a] << '\n';
    }
    return 0;
}

/*
8 12
0 1 15
5 1 4
6 5 5
4 6 7
7 4 8
3 5 10
2 0 2
5 1 9
5 4 5
4 1 8
6 2 10
2 6 7
2
4 6
3
3
0
2
*/