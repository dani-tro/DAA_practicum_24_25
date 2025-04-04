#include <iostream>
#include <algorithm>
using namespace std;

const size_t maxsize = 1e5;
long long l[maxsize];
long long r[maxsize];
long long n, m;

bool canBePut(long long minDist)
{
	long long putCoins = 1; // on l[0]
	long long lastCoin = l[0];
	long long currInterval = 0;
	while (currInterval < m && putCoins < n)
	{
		if (r[currInterval] - lastCoin >= minDist)
		{
			if (lastCoin >= l[currInterval])
			{
				lastCoin += minDist;
			}
			else
			{
				if (minDist + lastCoin >= l[currInterval])
				{
					lastCoin += minDist;
				}
				else
				{
					lastCoin = l[currInterval];
				}
			}
			++putCoins;
		}
		else
		{
			++currInterval;
		}
	}
	return putCoins == n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (size_t i = 0; i < m; i++)
	{
		cin >> l[i] >> r[i];
	}
	sort(l, l + m);
	sort(r, r + m);
	long long maxDist = r[m - 1];
	long long left = 0, right = maxDist / n + 1;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (canBePut(mid))
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	if(canBePut(left))
		cout << left << endl;
	else
	{
		cout << left - 1 << endl;
	}
	return 0;
}