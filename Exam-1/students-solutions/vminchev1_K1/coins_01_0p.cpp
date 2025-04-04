#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int lin;
vector<lin> x;
vector<lin> l;
vector<lin> t;
vector<pair<lin, bool>> planks;
bool check3(lin mid, lin n, lin m) {
	lin counter = 0;
	lin curr = 0;
	lin max = planks.size();
	while (n != 0 && counter <= m * 2 - 1)
	{
		while (planks[counter + 1].first < curr) {
			m--;
			counter += 2;
			if (counter >= max) return false;
		}
		if (planks[counter].first > curr) {
			curr = planks[counter].first;
			n--;
		}
		else {
			curr += mid;
			n--;
		}
	}
	return n == 0;
}

int main() { //3
	lin n, m, sum = 0;
	cin >> n >> m;
	for (size_t i = 0; i < m; i++)
	{
		lin l;
		cin >> l;
		planks.push_back(pair<lin, bool>(l, 0));
		sum -= l;
		cin >> l;
		planks.push_back(pair<lin, bool>(l, 1));
		sum += l;
	}
	sort(planks.begin(), planks.end());
	lin l = 0;
	lin r = sum;
	while (l < r) {
		lin mid = (l + r + 1) / 2;
		if (check3(mid, n, m)) {
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << l;
}