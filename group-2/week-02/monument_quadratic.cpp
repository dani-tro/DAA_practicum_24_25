#include <bits/stdc++.h>

using namespace std;

#define MAX 310000

int n, k, a[MAX], ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	long long cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for(int i = 0; i < n; i++)
	{
		int j;
		for(j = i+1; j < n; j++)
		{
			if (a[j]-a[i] > k) 
			{
				cnt += n - j;
				break;
			}
		}
	}
	cout << cnt << endl;
	
	return 0;
}
