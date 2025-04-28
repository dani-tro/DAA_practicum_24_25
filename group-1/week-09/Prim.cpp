#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

vector <pair <int, long long> > v[MAXN];

bool used[MAXN];

long long sum;
void prim() {
    priority_queue <pair <long long, int> > q;
    q.push({0, 1});
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        if (used[p.second]) continue;
        used[p.second] = true;

        sum += (-p.first);
        for (auto i : v[p.second]) {
            if (used[i.first]) continue;
            q.push({-i.second, i.first});
        }
    }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    prim();

    bool connected = true;

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            connected = false;
            break;
        }
    }
    if (!connected) cout << "IMPOSSIBLE\n";
    else cout << sum << endl;
    return 0;
}