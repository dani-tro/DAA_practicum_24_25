#include <bits/stdc++.h>

using namespace std;

#define MAX 15000

int n, a[MAX], b[MAX], h[MAX], dp[MAX], ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> h[i] >> a[i] >> b[i];
	}
	
	a[0] = b[0] = 15000;
	for(int i = 1; i <= n; i++)
	{
		for(int k = 0; k < i; k++)
		{
			if(a[k] >= a[i] && b[k] >= b[i] || a[k] >= b[i] && b[k] >= a[i])
			{
				dp[i] = max(dp[i], dp[k] + h[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}
