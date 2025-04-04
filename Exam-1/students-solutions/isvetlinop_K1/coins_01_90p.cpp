#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long

bool can(int n, int m, const std::vector<ull>& intervals, ull mid)
{
	int coins = 1, i = 0;
	ull pos = intervals[0];

	while (i < 2 * m && coins < n && pos <= intervals[2 * m - 1])
	{
		ull nextpos = pos + mid;
		if (nextpos <= intervals[i + 1])
		{
			coins++;
			pos = nextpos;
			continue;
		}
		while (i < 2 * m && nextpos >= intervals[i])
		{
			i++;
		}
		if (i == 2 * m)
		{
			break;
		}
		i--;
		if (i % 2)
		{
			if (nextpos == intervals[i])
			{
				pos = nextpos;
			}
			else
			{
				i++;
				pos = intervals[i];
			}
		}
		else
		{
			pos = nextpos;
		}
		coins++;
	}

	return coins >= n;
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int n, m;
	std::vector<ull> intervals;
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		ull a, b;
		std::cin >> a >> b;
		intervals.push_back(a);
		intervals.push_back(b);
	}

	std::sort(intervals.begin(), intervals.end());

	ull l = 0, r = 1e18;
	while (l < r - 1)
	{
		ull mid = (l + r) / 2;
		if (can(n, m, intervals, mid))
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}

	std::cout << l << '\n';

	return 0;
}