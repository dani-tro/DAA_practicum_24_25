#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

int n, m, k, a, b, c, d, dist[MAX];

bool used[MAX];

#define PA pair<int, int> 

priority_queue<PA, vector<PA>, greater<PA> > pq;

struct neighbour
{
	int u, p, t;
};

vector<neighbour> gr[MAX];

bool check(int x)
{
	pq.push({0, 1});
	fill(dist, dist + n + 5, k + 1); 
	// <==> for(int i = 0; i < n + 5; i++) dist[i] = k + 1;
	fill(used, used + n + 5, 0);
	
	dist[1] = 0;
	
	while(!pq.empty())
	{
		int node = pq.top().second;
		pq.pop();
		if(used[node])continue;
		used[node] = true;
		
		for(auto adj : gr[node])
		{
			if(adj.p <= x && dist[adj.u] > dist[node] + adj.t)
			{
				dist[adj.u] = dist[node] + adj.t;
				pq.push({dist[adj.u], adj.u});
			}
		}
	}
	return (dist[n] <= k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c >> d;
		gr[a].push_back({b, c, d});
	}
	
	int l = 1, r = 1001000, mid, opt = -1;
	
	while(l <= r)
	{
		mid = (l + r) / 2;
		
		if(check(mid))
		{
			r = mid - 1;
			opt = mid;
		}
		else l = mid + 1;
	}
	
	cout << opt << endl;
	return 0;
}
