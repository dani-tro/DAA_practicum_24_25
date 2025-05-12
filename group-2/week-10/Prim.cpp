#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

#define PA pair<int, int> 

long long n, m, a, b, c, ans, cnt;

bool used[MAX];

vector<pair<int, int> > gr[MAX];

priority_queue<PA, vector<PA>, greater<PA> > pq;

void Prim(int node)
{
	for(auto p : gr[node])
	{
		pq.push({p.second, p.first});
	}
	used[node] = true;
	
	while(!pq.empty())
	{
		node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(used[node] == true)continue;
		used[node] = true;
		ans += cost;
		cnt++;
		
		for(auto p : gr[node])
		{
			if(!used[p.first])
			{
				pq.push({p.second, p.first});
			}
		}
	}
	
	if(cnt == n - 1)
		cout << ans << endl;
	else 
		cout << "IMPOSSIBLE" << endl;
 	return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		
		gr[a].push_back({b, c});
		gr[b].push_back({a, c});
	}
	
	Prim(1);
	    
    return 0;
}
