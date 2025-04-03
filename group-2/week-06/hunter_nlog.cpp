#include <bits/stdc++.h>

using namespace std;

#define MAX 1000100

long long n, L, d, f, a, b, x[MAX], y[MAX];

pair<int, int> p[MAX];

bool check(int m)
{
	int ptr = 1;
	for(int i = 1; i <= n; i++)
	{
		if(p[i].second <= m)y[ptr++] = p[i].first;
	} 
	
	if(y[1] - 0 > d)return false;
	for(int i = 2; i <= m; i++)
	{
		if(y[i] - y[i - 1] > d)return false;
	}
	if(L - y[m] > d)return false;
	
	return true;
}

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> L >> d;
	cin >> f >> a >> b;
	x[1] = f;
	for(int i = 2; i <= n; i++) x[i] = (a * x[i - 1] + b) % (L + 1);
	for(int i = 1; i <= n; i++)
	{
		p[i] = {x[i], i};
	}
	sort(p + 1, p + n + 1, cmp);
	
	int l = 1, r = n, mid, opt = -1;
	
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
	
	if(check(l) == true)cout << l << "\n";
	else cout << "-1\n";
		
	return 0;
}
