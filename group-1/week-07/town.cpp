#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

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

    int a, b, u, s;
    cin >> n >> a >> b;
    while(cin >> u >> s) {
        v[u].push_back({s, 0});
        v[s].push_back({u, 1});
    }
    dijkstra(a);

    if (dist[b] == -1) cout << "X\n";
    else cout << dist[b] << '\n';
    return 0;
}