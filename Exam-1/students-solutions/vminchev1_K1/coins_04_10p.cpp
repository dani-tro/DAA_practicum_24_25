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
	lin n0 = n, m0 = m;
	bool flag = 0;
	while (n0 != 0 && counter <= m0 * 2 - 1)
	{
		while (planks[counter + 1].first < curr) {
			m0--;
			counter += 2;
			if (counter >= max)
			{
				flag = 1;
				break;
			}
		}
		if (flag) break;
		if (planks[counter].first > curr) {
			curr = planks[counter].first;
			n0--;
		}
		else {
			curr += mid;
			n0--;
		}
	}
	if (n0 == 0) return true;
	else {
		counter = max - 2;
		curr = planks[counter + 1].first;
		flag = 0;
		n0 = n, m0 = m;
		while (n0 != 0 && counter > 0)
		{
			while (planks[counter].first > curr) {
				m0--;
				counter -= 2;
				if (counter < 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag) break;
			if (planks[counter + 1].first < curr) {
				curr = planks[counter + 1].first;
				n0--;
			}
			else {
				curr -= mid;
				n0--;
			}
		}
		return n0 == 0;
	}
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
			if (r == mid && r == l + 1)
				r = l;
			else
				r = mid;
		}
	}
	cout << l;
}
