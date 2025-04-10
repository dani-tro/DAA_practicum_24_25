# include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
vector <pair <int, int > > g[maxn];
bool vis[maxn];
int k;
void dfs(int v)
{
    vis[v] = true;
    for(auto p : g[v])
    {
        if (p.second >= k && !vis[p.first]) dfs(p.first);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin >> k;
    int cc = 0;
    for(int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cc++;
            dfs(i);
        }
    }
    cout << cc - 1 << endl;
}