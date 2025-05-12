
#include <bits/stdc++.h>

using namespace std;

#define MAX 2048

int n, a, b, mat[MAX][MAX], mn, dist[MAX], par[MAX], d[MAX], idx;

vector<pair<int, int> > gr[MAX];

int find(int v)
{
	if(par[v] == 0)return v;
	return par[v] = find(par[v]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if(d[a] > d[b])
	{
		par[b] = a;
	}
	else
	{
		par[a] = b;
		if(d[a] == d[b])d[b]++;
	}
	return;
}

struct edge 
{
	int val, a, b;
	bool operator<(const edge& other) const
	{
		return val > other.val;	
	}
};

priority_queue<edge> pq;

bool used[MAX];

void precheck()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(mat[i][i] != 0 || mat[i][j] != mat[j][i] || (i != j && mat[i][j] == 0))
			{
				printf("NO\n");
				exit(0);
			}
		}
	}
}

void dfs(int v, int d)
{
	dist[v] = d;
	used[v] = true;
	for(int i = 0; i < gr[v].size(); i++)
	{
		if(!used[gr[v][i].first])
		{
			dfs(gr[v][i].first, d + gr[v][i].second);
		}
	}
	return ;
}

void check()
{
	for(int i = 1; i <= n; i++)
	{
		fill(used, used + n + 1, false);
		dfs(i, 0);
		for(int j = 1; j <= n; j++)
		{
			if(dist[j] != mat[i][j])
			{
				printf("NO\n");
				exit(0);
			}
		}
	}
	return ;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &mat[i][j]);
			if(i > j)pq.push({mat[i][j], i, j});
		}
	}
	
	precheck();
	
	while(!pq.empty())
	{
		mn = pq.top().val;
		a = pq.top().a;
		b = pq.top().b;
		pq.pop();
		if(find(a) == find(b))continue;
		
		gr[a].push_back({b, mn});
		gr[b].push_back({a, mn});
		uni(a, b);
	}
	
	check();

	printf("YES\n");
	
	return 0;
}

/*

10 
0 4 2 6 10 7 3 7 5 6
4 0 6 2 14 11 7 11 1 10
2 6 0 8 8 5 1 9 7 4
6 2 8 0 16 13 9 13 3 12 
10 14 8 16 0 13 7 17 15 10
7 11 5 13 13 0 6 14 12 9
3 7 1 9 7 6 0 10 8 3
7 11 9 13 17 14 10 0 12 13
5 1 7 3 15 12 8 12 0 11
6 10 4 12 10 9 3 13 11 0

3
0 10 4
10 0 13
4 13 0


10
1 2 4
2 4 2
1 3 2
3 7 1
7 5 7
3 6 5
1 8 7
2 9 1
7 10 3

*/
