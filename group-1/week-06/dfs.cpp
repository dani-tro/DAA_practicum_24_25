# include <bits/stdc++.h>
using namespace std;
int const maxn = 105;
vector <int> g[maxn];
bool vis[maxn];
void dfs(int v)
{
    cout << v << " ";
    vis[v] = true;

    for(int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (vis[u] == false)
        {
            dfs(u);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    dfs(0);
}