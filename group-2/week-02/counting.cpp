#include <bits/stdc++.h>

using namespace std;

#define MAX 1200

int n, a, cnt[MAX];

int main()
{
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		cnt[a]++;
	}
	
	for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < cnt[i]; j++)cout << i << " ";
	}
	cout << endl;
	return 0;
}
