#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int lin;
vector<lin> x;
vector<lin> l;
vector<lin> t;
vector<pair<lin, bool>> planks;
vector<pair<lin, lin>> leters;

bool cmp(const pair<lin, lin> &a, const pair<lin, lin> &b) {
	return min(a.first, a.second) < min(b.first, b.second);
}

void pushdown(vector<pair<lin, lin>> &a) {
	lin last = a.size() - 1; 
	pair<lin, lin> zaqk;
	while (!cmp(a[last - 1], a[last]) && last != 1) {
		zaqk = a[last - 1];
		a[last - 1] = a[last];
		a[last] = zaqk;
		last--;
	}
}

int main() { //2
	lin n, k;
	cin >> n >> k;
	for (size_t i = 0; i < n; i++)
	{
		lin a, b;
		cin >> a >> b;
		leters.push_back(pair<lin, lin>(a, b));
	}
	sort(leters.begin(), leters.end(), cmp);
	lin result = 0;
	lin size = leters.size();
	for (size_t i = 0; i < k; i++)
	{
		lin curr = min(leters[size - 1].first, leters[size - 1].second);
		result += curr;
		leters[size - 1].first -= curr;
		pushdown(leters);
	}
	cout << result;
}