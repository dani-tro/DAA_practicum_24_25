#include <bits/stdc++.h>

using namespace std;

#define MAXK 11000

#define MAXN 1010

int n, m, k, a, b, c, par[MAXN], d[MAXN];

bool used[MAXN];

struct edge
{
	int a, b, c;
	
	bool operator<(const edge& other) const
	{
		return c > other.c;
	}
};

vector<pair<int, int> > gr[MAXN];;

vector<edge> edges;

int find(int a)
{
	if (par[a] == 0) return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	
	if(a == b)return ;
	
	if(d[a] > d[b])
	{
		par[b] = a;
	}
	else 
	{
		par[a] = b;
		if(d[a] == d[b])d[b]++;
	}
	return ;
}

void Kruskal()
{
	sort(edges.begin(), edges.end());
	for(auto e : edges)
	{
		if(find(e.a) == find(e.b))continue;
		
		uni(e.a, e.b);
		gr[e.a].push_back({e.b, e.c});
		gr[e.b].push_back({e.a, e.c});
	}
	return;
}

int dfs(int u, int v, int d)
{
	if (u == v) return d;
	
	int res = INT_MAX / 2;
	used[u] = true;
	
	for (auto p : gr[u])
	{
		if(used[p.first])continue;
		res = min(res, dfs(p.first, v, min(d, p.second)));
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
	}
	
	Kruskal();
	
	for(int i = 0; i < k; i++)
	{
		fill(used, used + n + 5, 0);
		cin >> a >> b;
		cout << dfs(a, b, INT_MAX / 2) << endl;
	}
	
	return 0;
}
