#include <bits/stdc++.h>

using namespace std;

#define MAX 1010000

int n, a[MAX], b[MAX];

long long merge(long long l1, long long r1, long long l2, long long r2)
{
	long long i = l1, j = l2, pos = 0, cnt = 0;
	while(i <= r1 && j <= r2)
	{
		if(a[i] < a[j])
		{
			b[pos++] = a[i++];
			cnt += (j - l2);
		}
		else
		{
			b[pos++] = a[j++];
		}
	}
	
	while(i <= r1)
	{
		cnt += (j - l2);
		b[pos++] = a[i++];
	}
	while(j <= r2)
	{
		b[pos++] = a[j++];
	}
	
	for(long long i = l1; i <= r2; i++)
	{
		a[i] = b[i - l1];
	}
	return cnt;
}


long long mergeSort(long long l, long long r, long long level)
{
	if(l == r)
	{
		return 0;
	}
	
	long long mid = (l + r) / 2;
	long long li = mergeSort(l, mid, level + 1);
	long long ri = mergeSort(mid + 1, r, level + 1);
	
	long long mi = merge(l, mid, mid + 1, r);
	
	
	return li + ri + mi;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(long long i = 0; i < n; i++)cin >> a[i];
	
	cout << mergeSort(0, n - 1, 0) << endl;
	
	
	return 0;
}
