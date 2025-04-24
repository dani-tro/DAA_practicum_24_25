# include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int vis[maxn], cnth, cntl;
vector <pair <int, bool> > g[maxn];
void dfs(int v)
{
    if(vis[v] == 1) cnth ++;
        else cntl++;
    for(auto u : g[v])
    {
        if(!vis[u.first])
        {
            if (vis[v] == 1 && u.second == 1) vis[u.first] = 1;
            if (vis[v] == 1 && u.second == 0) vis[u.first] = 2;
            if (vis[v] == 2 && u.second == 1) vis[u.first] = 2;
            if (vis[v] == 2 && u.second == 0) vis[u.first] = 1;
            dfs(u.first);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    char ch;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> ch >> v;
        g[u].push_back({v,ch=='h'});
        g[v].push_back({u,ch=='h'});
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i);
            ans += max(cnth, cntl);
            cnth = cntl = 0;
        }
    }

    cout << ans << endl;
}