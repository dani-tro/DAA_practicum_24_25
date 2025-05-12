#include <bits/stdc++.h>

using namespace std;

#define MAXK 11000

#define MAXN 1010

int n, m, k, a, b, c, ans[MAXK], par[MAXN], d[MAXN];

struct edge
{
	int a, b, c;
	
	bool operator<(const edge& other) const
	{
		return c > other.c;
	}
};

pair<int, int> q[MAXK];

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
		
		//cout << e.a << " " << e.b << endl;
		
		uni(e.a, e.b);
		for(int i = 0; i < k; i++)
		{
			auto p = q[i];
			if(ans[i] == 0 && find(p.first) == find(p.second))
			{
				ans[i] = e.c;
			}
		}
	}
	return;
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
	for(int i = 0; i < k; i++)
	{
		cin >> q[i].first >> q[i].second;
	}
	
	Kruskal();
	
	for(int i = 0; i < k; i++)cout << ans[i] << endl;
	
	return 0;
}
