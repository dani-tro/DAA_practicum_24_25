# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
vector <pair <int, bool> > g[maxn];
bool vis[maxn];
bool liar[maxn];
int cnth = 0, cntl = 0;
void dfs(int v)
{
    //cout << v << " :: " << liar[v] << endl;
    vis[v] = true;
    if (liar[v]) cntl ++;
    else cnth ++;
    for(auto p : g[v])
    {
        if (!vis[p.first])
        {
            liar[p.first] = p.second ^ liar[v];
            dfs(p.first);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int i, j, x, y;
    char c;
    for(i = 1; i <= m; i++)
    {
        cin >> x >> c >> y;
        g[x].push_back({y, c == 'l'});
        g[y].push_back({x, c == 'l'});
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            liar[i] = 0;
            dfs(i);
            //cout << i << " " << cntl << " " << cnth << endl;
            ans += max(cntl, cnth);
            cntl = cnth = 0;
        }
    }
    cout << ans << endl;
}
