#include <bits/stdc++.h>

using namespace std;

#define MAX 1100000

long long n, L, d, f, a, b, x[MAX], y[MAX];

bool check(long long m)
{
	for(int i = 1; i <= m; i++)y[i] = x[i];
	sort(y + 1, y + 1 + m); 
	
	if(y[1] - 0 > d)return false;
	for(long long i = 2; i <= m; i++)
	{
		if(y[i] - y[i - 1] > d)return false;
	}
	if(L - y[m] > d)return false;
	
	return true;
}

int main()
{
	cin >> n >> L >> d;
	cin >> f >> a >> b;
	x[1] = f;
	for(long long i = 2; i <= n; i++) x[i] = (a * x[i - 1] + b) % (L + 1);
	
	long long l = 1, r = n, mid, opt = -1;
	
	while(l < r)
	{
		mid = (l + r) / 2;
		
		if(check(mid))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	if(check(l) == true)cout << l << endl;
	else cout << "-1" << endl;
		
	return 0;
}
