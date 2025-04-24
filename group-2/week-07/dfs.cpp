# include <bits/stdc++.h>
using namespace std;
const int maxN = 105;
vector <int> g[maxN];
bool vis[maxN];
void dfs(int v)
{
    cout << v << " ";
    vis[v] = true;
    for (auto u : g[v])
    {
        if (!vis[u]) dfs(u);
    }
    // for(int i = 0; i < g[v].size(); i++) // alternative way
    // {
    //     int u = g[v][i];
    //     if (!vis[u]) dfs(u);
    // }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++) sort(g[i].begin(), g[i].end());
    dfs(0);
    cout << endl;
}