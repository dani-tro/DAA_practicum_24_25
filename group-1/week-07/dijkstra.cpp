#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

vector <pair <int, int> > v[MAXN];
int dist[MAXN];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    int start;
    cin >> start;

    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < n; i++) cout << dist[i] << ' ';
    cout << endl;
    return 0;
}