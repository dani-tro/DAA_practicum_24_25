# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector <pair <int, long long> > g[maxn];
// long long cost[maxn];
long long d[maxn];
void dijkstra(int start)
{
    priority_queue <pair <long long, int> > pq;
    pq.push({0,start});
    fill(d,d+maxn,INT_MAX);
    d[start] = 0;
    while(!pq.empty())
    {
        int curr = pq.top().second;
        int val = -pq.top().first;
        pq.pop();
        if (d[curr] != val) continue;
        for(auto p : g[curr])
        {
            int w;
            if (curr == 0) w = p.second;
            else
                w = d[p.second];
            if (d[p.first] > d[curr] + w)
            {
                d[p.first] = d[curr] + w;
                pq.push({-d[p.first], p.first});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int i;
    int w;
    for(int i = 1; i <= n; i++)
    {
        cin >> w;
        g[0].push_back({i,w});
        // d[i] = w;
    }
    int a, x, y;
    for(int i = 1; i <= m; i++)
    {
        cin >> a >> x >> y;
        g[x].push_back({a,y});
        g[y].push_back({a,x});
    }
    dijkstra(0);
    cout << d[1] << endl;
}

/*
5 3
5 0 1 3 5
5 2 3
4 2 3
1 4 5
*/