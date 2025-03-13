#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

int n, m, a[MAX], b[MAX], ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)cin >> a[i];
	for(int i = 0; i < m; i++)cin >> b[i];
	
	sort(a, a + n);
	sort(b, b + m);
	
	int r = 0;
	
	for(int l = 0; l < n; l++)
	{
		while(r < m && b[r] < a[l])r++;
		if(r < m)
		{
			ans++;
			r++;
		}
	}
	cout << ans << endl;
	return 0;
}
