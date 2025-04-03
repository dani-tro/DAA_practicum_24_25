#include <bits/stdc++.h>

using namespace std;

#define MAX 1000100

long long n, L, d, f, a, b, x[MAX], curr = 0;

priority_queue<int, vector<int>, greater<int> > pq;

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
		if(curr > x[i])continue;
		else if(curr >= x[i] - d)curr = max(curr, x[i]);
		else
		{
			pq.push(x[i]);
		}
		while(!pq.empty() && pq.top() - d <= curr)
		{
			curr = max(curr, (long long)pq.top());
			pq.pop();
		}
		if(curr >= L - d)
		{
			cout << i << endl;
			return 0;
		}
	}
	
	cout << "-1" << endl;
		
	return 0;
}
