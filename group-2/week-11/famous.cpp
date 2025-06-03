# include <bits/stdc++.h>
using namespace std;
map <string, int> mp;
queue <int> q;
const int maxn = 1005;
vector <int> g[maxn];
int d[maxn];
bool famous[maxn];
vector <string> ans;
set <pair <int, int> > st;
int main()
{
    int n, k, f, m;
    cin >> n >> k >> f >> m;
    string a, b;
    for (int i = 1; i <= f; i++)
    {
        cin >> a;
        mp[a] = i;
        q.push(i);
        famous[i] = true;
    }
    int cnt = f;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if(mp.find(a)==mp.end())
        {
            cnt++;
            mp[a] = cnt;
        }
        if(mp.find(b)==mp.end())
        {
            cnt++;
            mp[b] = cnt;
        }
        if (st.find({mp[a],mp[b]}) != st.end()) continue;
        if (st.find({mp[b],mp[a]}) != st.end()) continue;
        g[mp[a]].push_back(mp[b]);
        g[mp[b]].push_back(mp[a]);
        st.insert({mp[a],mp[b]});
        st.insert({mp[b],mp[a]});
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto u : g[v])
        {
            if (famous[u]) continue;
            d[u]++;
            if (d[u] >= k)
            {
                famous[u] = true;
                q.push(u);
            }
        }
    }
    for (auto p : mp)
    {
        if (famous[p.second]) ans.push_back(p.first);
    }

    sort(ans.begin(), ans.end());
    for(auto s : ans)
    {
        cout << s << " ";
    }
    cout << endl;

}