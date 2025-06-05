#include <bits/stdc++.h>

using namespace std;

#define MAX 102

#define MOD 1000000007

long long n, dp[MAX][MAX];

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	n = s.size();
	
	for(int i = 0; i < n; i++)dp[i][i] = 1;
	
	for(int k = 1; k < n; k++)
	{
		for(int l = 0; l < n - k; l++)
		{
			dp[l][k + l] = 1;
			
			dp[l][k + l] += dp[l][k + l - 1];
			for(int t = l; t <= k + l - 1; t++)
			{
				if(s[t] == s[k + l])
				{
					dp[l][k + l] = (dp[l][k + l] + dp[t + 1][k + l - 1] + 1) % MOD;
				}
			}
		}
	}
	
	cout << dp[0][n - 1] << endl;
	return 0;
}
