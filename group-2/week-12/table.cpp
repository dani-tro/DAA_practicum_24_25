#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

int n, m, mat[MAX][MAX], dp[MAX][MAX];


int calc(int i, int j)
{
	if(i <= 0 || i >= n + 1)return INT_MAX / 2;
	if(j == 1)
	{
		return dp[i][j] = mat[i][j];
	}
	if(dp[i][j] != 0)
	{
		return dp[i][j];
	}
	
	int ans = INT_MAX;
	ans = min(ans, calc(i - 1, j - 1) + mat[i][j]);
	ans = min(ans, calc(i, j - 1) + mat[i][j]);
	ans = min(ans, calc(i + 1, j - 1) + mat[i][j]);
	
	return dp[i][j] = ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> mat[i][j];
		}
	}
	
	
	int ans = INT_MAX;
	for(int i = 1; i <= n; i++)
	{
		ans = min(ans, calc(i, m));
	}
	cout << ans << endl;
	
	return 0;
}
