#include <iostream>
#include <algorithm>

const int MAXN = 200000;

int res[MAXN + 5];

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> res[i];
	}

	std::sort(res, res + n);

	int l = 0, ans = 0;
	for (int r = 1; r < n; ++r)
	{
		while (res[l] + res[l + 1] <= res[r])
		{
			++l;
		}
		ans = std::max(ans, r - l + 1);
	}

	std::cout << ans << '\n';

	return 0;
}