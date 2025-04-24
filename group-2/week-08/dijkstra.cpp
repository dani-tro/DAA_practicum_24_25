#include <bits/stdc++.h>

using namespace std;

#define MAX 1100

#define PA pair<int, int> 

int n, m, a, b, c, s, d[MAX];

vector<pair<int, int> > gr[MAX];

bool used[MAX];

priority_queue<PA, vector<PA>, greater<PA> > pq;

void dijkstra(int node)
{
	for(int i = 0; i <= n; i++)
	{
		d[i] = INT_MAX / 2;
	}
	d[node] = 0;
	pq.push({0, node});
	
	while(!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		
		if(used[node])continue;
		used[node] = 1;
		
		for(auto p : gr[node])
		{
			if(d[p.first] > d[node] + p.second)
			{
				d[p.first] = d[node] + p.second;
				pq.push({d[p.first], p.first});
			}
		}
	}
	
	for(int i = 0; i < n; i++)cout << d[i] << " " ;
	cout << endl;
	
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		gr[a].push_back({b, c});
		gr[b].push_back({a, c});
	}
	
	cin >> s;
	
	dijkstra(s);
	
	return 0;
}
