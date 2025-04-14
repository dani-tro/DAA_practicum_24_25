#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 10;
const int INF = 1e6;

struct Edge {
    int to;
    int p;
    int t;
};

vector <Edge> v[MAXN];
bool used[MAXN];
int dist[MAXN];
int n;
void dijkstra(int start, int C) {
    fill(dist, dist+n+1, -1);
    fill(used, used+n+1, false);

    priority_queue<pair <int, int> > q;
    dist[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        int x = q.top().second;
        q.pop();

        if (used[x]) continue;
        used[x] = true;

        for (auto i : v[x]) {
            if (i.p > C) continue;
            if (dist[i.to] == -1 || dist[i.to] > dist[x] + i.t) {
                dist[i.to] = dist[x] + i.t;
                q.push({-dist[i.to], i.to});
            }
        }
    }
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, p, t;
        cin >> a >> b >> p >> t;
        v[a].push_back({b, p, t});
    }
    
    int l, r, mid;
    l = 0; r = INF;
    int ans = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        dijkstra(1, mid);
        if (dist[n] != -1 && dist[n] <= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}