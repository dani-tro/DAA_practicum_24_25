#include <bits/stdc++.h>

using namespace std;

#define MAX 5100

#define INF INT_MAX / 2

int n, a[MAX], last[MAX], ans;

int lower_bound(int x)
{
	int l = 0, r = n, mid, opt = 0;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(x <= last[mid])
		{
			r = mid - 1;
			opt = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return opt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		last[i] = INF;
	}
	
	for(int i = 1; i <= n; i++)
	{
		int idx = lower_bound(a[i]);
		last[idx] = a[i];
		ans = max(ans, idx);
	}
	
	cout << ans << endl;
	return 0;
}
