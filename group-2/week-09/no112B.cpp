# include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1005;
int comp[maxn];
int h[maxn];
int find(int v)
{
    if (comp[v] == v) return v;
    return comp[v] = find(comp[v]);
}
void Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return ;
    if (h[u] > h[v]) swap(u,v);
    comp[u] = v;
    if (h[u] == h[v]) h[v]++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    int i, j, u, v;
    for(i = 1; i <= n; i++)
    {
        comp[i] = i;
        h[i] = 0;
    }
    for(i = 1; i <= m; i++)
    {
        cin >> u >> v;
        Union(u, v);
    }
    int q, t;
    cin >> q;
    for(i = 1; i <= q; i++)
    {
        cin >> t >> u >> v;
        if (t == 1)
        {
            cout << (find(u) == find(v));
        } else
        {
            Union(u, v);
        }
    }
    cout << endl;

}