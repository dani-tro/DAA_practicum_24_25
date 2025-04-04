#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

int n, m;

pair<long long, long long> p[MAX];

bool check(long long x)
{
	long long cnt = 1, curr = p[0].first;
	for(int i = 0; i < m; i++)
	{
		if(curr + x < p[i].first)
		{
			curr = p[i].first;
			cnt++;
			
		}
		else if(curr + x <= p[i].second)
		{
			curr += x;
			cnt++;
		}
		
		if(cnt >= n)return true;
		while(curr + x <= p[i].second)
		{
			curr += x;
			cnt++;
			if(cnt >= n)return true;
		}
	}
	return (cnt >= n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	
	sort(p, p + m);
	
	long long l = 1, r = LLONG_MAX / 4, mid, opt;
	
	while(l <= r)
	{
		mid = (l + r) / 2;
		
		if(check(mid))
		{
			l = mid + 1;
			opt = mid;
		}
		else r = mid - 1;
	}
	
	cout << opt << endl;
	
	return 0;
}
