#include <bits/stdc++.h>

using namespace std;

#define MAX 1200

int n, a[MAX];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)cin >> a[i];
	
	for(int i = 1; i < n; i++)
	{
		int j = i;
		while(j > 0 && a[j] < a[j - 1])
		{
			swap(a[j], a[j - 1]);
			j--;
		}
		
		for(int i = 0; i < n; i++)cout << a[i] << " ";
		cout << endl;
	}
	
	
	return 0;
}
