# include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
vector <int> g[maxn];
bool vis[maxn];
void bfs(int startnode)
{
    queue <int> q;
    q.push(startnode);
    vis[startnode] = true;
    while(!q.empty())
    {
        int v = q.front();

        q.pop(); // VERY IMPORTANT
        cout << v << " ";
        for(auto u : g[v])
        {
            if (vis[u] == false)
            {
                vis[u] = true;
                q.push(u);
            }
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
        sort(g[i].begin(), g[i].end());
    bfs(0);
}