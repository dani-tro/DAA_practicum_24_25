# include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int comp[maxn];
int sz[maxn];
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
    sz[v] += sz[u];
    if (h[u] == h[v]) h[v]++;
}
void print(int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << i << " : " << comp[i] << " " << sz[i] << " " << h[i] << endl;
     }

}
void solve()
{
    string s;
    cin >> s;
    stack < pair <pair <int,int>, char>  > queries;
    int q;
    cin >> q;
    int t, p;
    for(int i = 1; i <= q; i++)
    {
        cin >> t >> p;
        queries.push({{t,p},s[p]});
        if (t == 2)
            s[p] = '#';
    }
    for (int i = 0; i < s.size(); i++)
    {
        comp[i] = i;
        h[i] = 0;
        sz[i] = 1;
    }
    for (int i = 0; i < s.size()-1; i++)
    {
        if (s[i] == s[i+1] && s[i] != '#') Union(i,i+1);
    }
    stack <int> ans;
    while(!queries.empty())
    {
        //print(s.size());
        //cout << s << endl;
        auto q = queries.top();
        queries.pop();
        if (q.first.first == 1)
        {
            ans.push(sz[find(q.first.second)]);
        }
        else
        {
            int pos = q.first.second;
            s[pos] = q.second;
            if (pos > 0 && s[pos-1] == s[pos]) Union(pos-1,pos);
            if (pos < s.size()-1 && s[pos] == s[pos+1]) Union(pos,pos+1);
        }
    }
    while(!ans.empty())
    {
        cout << ans.top() << '\n';
        ans.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":" << '\n';
        solve();
    }
}