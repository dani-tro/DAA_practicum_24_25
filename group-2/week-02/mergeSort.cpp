#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

int n, a[MAX], b[MAX], print[20][MAX], maxLevel;

void merge(int l1, int r1, int l2, int r2)
{
	int i = l1, j = l2, pos = 0;
	while(i <= r1 && j <= r2)
	{
		if(a[i] < a[j])
		{
			b[pos++] = a[i++];
		}
		else
		{
			b[pos++] = a[j++];
		}
	}
	
	while(i <= r1)
	{
		b[pos++] = a[i++];
	}
	while(j <= r2)
	{
		b[pos++] = a[j++];
	}
	
	for(int i = l1; i <= r2; i++)
	{
		a[i] = b[i - l1];
	}
	return;
}


void mergeSort(int l, int r, int level)
{
	if(l == r)
	{
		print[level][r] = a[r];
		maxLevel = max(level, maxLevel);
		return ;
	}
	
	int mid = (l + r) / 2;
	mergeSort(l, mid, level + 1);
	mergeSort(mid + 1, r, level + 1);
	
	merge(l, mid, mid + 1, r);
	
	for(int i = l; i <= r; i++)
	{
		print[level][i] = a[i];
	}
	maxLevel = max(level, maxLevel);
	
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++)cin >> a[i];
	
	mergeSort(0, n - 1, 0);
	
	for(int i = 0; i <= maxLevel; i++)
	{
		for(int j = 0; j < n; j++)cout << print[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
