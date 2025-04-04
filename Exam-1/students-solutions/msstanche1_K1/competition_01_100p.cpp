#include <iostream>
#include <algorithm>
using namespace std;

const size_t maxsize = 2e6;
long x[maxsize];
long n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	sort(x, x + n);
	long maxcount = 2;
	long end = 1;
	for (size_t start = 0; start < n - 1;)
	{
		while (end < n && x[start] + x[start + 1] > x[end])
			++end;
		if (end == n)
		{
			if (end - start > maxcount)
			{
				maxcount = end - start;
			}
			break;
		}
		if (end - start > maxcount)
		{
			maxcount = end - start;
		}
		while (start < n && x[start] + x[start + 1] <= x[end])
		{
			++start;
		}
	}
	cout << maxcount << endl;
	return 0;
}