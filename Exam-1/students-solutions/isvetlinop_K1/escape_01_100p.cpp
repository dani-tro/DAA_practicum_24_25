#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define ull unsigned long long

bool cmp(std::pair<ull, ull> a, std::pair<ull, ull> b)
{
	return a.first > b.first;
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	int n;
	ull k;
	std::vector<std::pair<ull, ull> > quantities;
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		ull li, ti;
		std::cin >> li >> ti;
		quantities.push_back({ ti, li / ti });
		quantities.push_back({ li % ti, 1 });
	}

	std::sort(quantities.begin(), quantities.end(), cmp);

	ull ans = 0;
	for (auto& quantity : quantities)
	{
		if (k <= quantity.second)
		{
			ans += k * quantity.first;
			break;
		}
		ans += quantity.second * quantity.first;
		k -= quantity.second;
	}

	std::cout << ans << '\n';

	return 0;
}
