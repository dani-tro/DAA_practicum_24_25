#include <bits/stdc++.h>

using namespace std;

#define MAX 1100000

long long n, m, a[MAX], b[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++)cin >> a[i];
	for(int i = 0; i < m; i++)cin >> b[i];
	
	int l = 0, r = 0;
	while(l < n && r < m)
	{
		if(a[l] < b[r])cout << a[l++] << " ";
		else cout << b[r++] << " ";
 	}
 	while(l < n)cout << a[l++] << " ";
 	while(r < m)cout << b[r++] << " ";
 	cout << endl;
 	
	return 0;
}
