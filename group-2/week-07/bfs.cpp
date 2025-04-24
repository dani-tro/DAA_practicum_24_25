# include <bits/stdc++.h>
using namespace std;
const int maxN = 105;
vector <int> g[maxN];
bool vis[maxN];
void bfs(int v)
{
    queue <int> q;
    q.push(v);
    vis[v] = true;
    while(!q.empty())
    {
        v = q.front();
        cout << v << " ";
        q.pop(); // VERY IMPORTANT
        for(auto u : g[v])
        {
            if (!vis[u])
            {
                q.push(u);
                vis[u] = true;
                //cout << v << " add " << u << " to the queue" << endl;
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
    for (int i = 0; i < n; i++) sort(g[i].begin(), g[i].end());
    bfs(0);
    cout << endl;
}