#include <bits/stdc++.h>

using namespace std;

#define MAX 1000100

int n, m, u, v, cnt;

vector<int> gr[MAX];

bool vis[MAX];

void dfs(int node)
{
	vis[node] = true;
	for(auto u : gr[node])
	{
		if(!vis[u])
		{
			dfs(u);
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt << endl;
	return 0;
}
