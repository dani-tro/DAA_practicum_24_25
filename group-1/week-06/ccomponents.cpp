# include <bits/stdc++.h>
using namespace std;
int const maxn = 1e6+5;
vector <int> g[maxn];
bool vis[maxn];
void dfs(int v)
{
    //cout << v << " ";
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
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cc = 0;
    for(int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cc++;
            dfs(i);
        }
    }
    cout << cc << endl;
}