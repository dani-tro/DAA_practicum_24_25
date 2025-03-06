#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int n, a[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++)cin >> a[i];
	
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(a[j] > a[j + 1])swap(a[j], a[j + 1]);
		}
		for(int j = 0; j < n; j++)cout << a[j] << " ";
		cout << endl;
	}
	
	return 0;
}
