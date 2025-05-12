#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

long long n, m, a, b, c, ans, par[MAX], d[MAX], cnt;

struct edge
{
	long long a, b, c;
	
	bool operator<(const edge& other) const
	{
		return (c < other.c);
	}
};

vector<edge> edges;

int find(int a)
{
	if(par[a] == a) return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	
	if(a == b)return;
	
	if(d[a] < d[b])swap(a, b);
	par[b] = a;
	if(d[a] == d[b])d[a]++;
	return ;
}

void Kruskal()
{
	sort(edges.begin(), edges.end());
	
	for(auto e : edges)
	{
		if(find(e.a) == find(e.b))continue;
		
		ans += e.c;
		uni(e.a, e.b);
		cnt++;
	}
	
	if(cnt == n - 1)
		cout << ans << endl;
	else
		cout << "IMPOSSIBLE" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i <= n; i++)
	{
		par[i] = i;
	}
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
	}
	
	Kruskal();
	
	return 0;
}
