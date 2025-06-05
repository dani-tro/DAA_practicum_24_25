#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

long long n, a[MAX], dp[MAX][MAX];

long long sum(int l, int r)
{
	long long res = 0;
	for(int i = l; i <= r; i++)res += a[i];
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	for(int k = 1; k < n; k++)
	{
		for(int l = 1; l <= n - k; l++)
		{
			dp[l][k + l] = LLONG_MAX / 2;
			
			long long s = sum(l, k + l);
			for(int t = l; t < k + l; t++)
			{
			
				dp[l][k + l] = min(dp[l][k + l], s + dp[l][t] + dp[t + 1][k + l]);
			}
		}
	}
	
	cout << dp[1][n] << endl;
	
	return 0;
}
