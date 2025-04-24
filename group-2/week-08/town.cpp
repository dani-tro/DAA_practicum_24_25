# include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
vector <pair <int, int> > g[maxn];
int d[maxn], n;
void bfs01(int s, int t)
{
    for(int i = 1; i <= n; i++) d[i] = INT_MAX / 2;
    deque <pair <int, int> > dq;
    d[s] = 0;
    dq.push_back({s,0});
    while(!dq.empty())
    {
        int curr = dq.front().first;
        int w = dq.front().second;
        dq.pop_front();
        if (d[curr] < w) continue;
        for (auto u : g[curr])
        {
            if (d[u.first] > u.second + d[curr])
            {
                d[u.first] = u.second + d[curr];
                if (u.second == 0) dq.push_front({u.first,d[u.first]});
                else
                    dq.push_back({u.first, d[u.first]});

            }
        }
    }
}
int main()
{
    int from, to;
    cin >> n >> from >> to;
    int u, v;
    while((cin >> u >> v))
    {
        g[u].push_back({v,0});
        g[v].push_back({u,1});
    }
    bfs01(from, to);
    if (d[to] == INT_MAX / 2) cout << "X\n";
    else
        cout << d[to] << endl;
}