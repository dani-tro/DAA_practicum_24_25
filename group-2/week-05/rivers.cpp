// O(2 ^ 2 * 128 ^ 3)

#include <bits/stdc++.h>

using namespace std;

double l, g, w[4], s[4];

double calc(int idx, double x)
{
	if(idx == 3)
	{
		return (l - x) * (1.0 / g);
	}
	double left = x, right = l, m1, m2;
	
	for(int i = 0; i < 128; i++)
	{
		m1 = left + (right - left) * (1.0 / 3);
		m2 = left + (right - left) * (2.0 / 3);
		double c1 = calc(idx + 1, m1) + 
					sqrt((m1 - x) * (m1 - x) + w[idx] * w[idx]) * (1.0 / s[idx]);
		double c2 = calc(idx + 1, m2) + 
					sqrt((m2 - x) * (m2 - x) + w[idx] * w[idx]) * (1.0 / s[idx]);
		if(c1 > c2)
		{
			left = m1;
		}
		else
		{
			right = m2;
		}
	}
	return calc(idx + 1, left) + 
				sqrt((left - x) * (left - x) + w[idx] * w[idx]) * (1.0 / s[idx]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> l >> g;
	for(int i = 0; i < 3; i++)cin >> w[i] >> s[i];
	
	cout << setprecision(10) << calc(0, 0) << endl;
	
	return 0;
}
