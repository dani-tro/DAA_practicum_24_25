#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

long long n, k, a[MAX], ans = -1, sum; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for(int i = 0; i < n; i++)cin >> a[i];
	
	int l = 0;
	
	for(int r = 0; r < n; r++)
	{
		sum += a[r];
		while(sum > k)sum -= a[l++];
		ans = max(ans, sum);
	}

	cout << ans << endl;
	
	return 0;
}
