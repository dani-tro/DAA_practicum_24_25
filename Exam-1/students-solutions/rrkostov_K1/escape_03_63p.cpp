#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	long long k;
	cin >> n >> k;
	priority_queue<pair<long long, long long>> l;
	pair<long long, long long> currPair;
	for (int i = 0; i < n; ++i) {
		cin >> currPair.second >> currPair.first;
		currPair.first = min(currPair.first, currPair.second);

		l.push(currPair);
	}

	long long i = 0, secondsToSkip, litresRes = 0;
	/*while (i < k && !l.empty()) {
		currPair = l.top();
		secondsToSkip = currPair.second / currPair.first;

		if (i + secondsToSkip >= k) {
			secondsToSkip = 1;
		}

		litresRes += secondsToSkip * currPair.first;
		currPair.second %= currPair.first;
		currPair.first = currPair.second;

		l.pop();
		if (currPair.first > 0) {
			l.push(currPair);
		}

		i += secondsToSkip;
	}*/
	while (i < k && !l.empty()) {
		currPair = l.top();

		litresRes += currPair.first;
		currPair.second -= currPair.first;
		currPair.first = min(currPair.second, currPair.first);

		l.pop();
		if (currPair.first > 0) {
			l.push(currPair);
		}

		++i;
	}

	cout << litresRes;

	return 0;
}