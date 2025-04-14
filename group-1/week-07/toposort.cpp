#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 10;

vector <int> v[MAXN], ans;

int in[MAXN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        in[b]++;
        v[a].push_back(b);
    }

    priority_queue <int> q;

    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(-i);
    }

    while (!q.empty()) {
        int x = -q.top();
        ans.push_back(x);
        q.pop();

        for (auto u : v[x]) {
            in[u]--;
            if (in[u] == 0) {
                q.push(-u);
            }
        }
    }
    if (ans.size() != n) {
        cout << "Sandro fails." << endl;
    } else {
        for (auto i : ans) cout << i << ' ';
        cout << endl;
    }
    cout << endl;
    return 0;
}