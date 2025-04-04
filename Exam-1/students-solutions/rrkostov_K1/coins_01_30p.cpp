#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> coords;
	long long currL, currR;
	for (int i = 0; i < m; ++i) {
		cin >> currL >> currR;
		while (currL <= currR) {
			coords.push_back(currL);
			++currL;
		}
	}
	sort(coords.begin(), coords.end());

	m = coords.size();
	long long minD = 1, maxD = coords[m - 1] - coords[0], currD, resD = 1, i, currCoord, nextCoord;
	int coinsLeft;

	while (minD <= maxD) {
		currD = minD + (maxD - minD) / 2;
		coinsLeft = n - 1;
		i = 0;
		currCoord = coords[0];

		while (i < m && coinsLeft > 0) {
			nextCoord = currCoord + currD;
			while (i < m && coords[i] < nextCoord) {
				++i;
			}
			if (i < m) {
				--coinsLeft;
				currCoord = coords[i];
			}
		}

		if (coinsLeft <= 0) {
			resD = max(resD, currD);
			minD = currD + 1;
		}
		else {
			maxD = currD - 1;
		}
	}

	cout << resD;

	return 0;
}