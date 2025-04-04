#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//struct Event {
//	long long coord;
//	int type;
//};

//bool sortEvents(const Event& event1, const Event& event2) {
//	if (event1.coord == event2.coord) {
//		return event1.type > event2.type;
//	}
//
//	return event1.coord < event2.coord;
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<pair<long long, long long>> events(m);
	for (int i = 0; i < m; ++i) {
		cin >> events[i].first >> events[i].second;
	}
	sort(events.begin(), events.end());

	long long minD = 1, maxD = events[m - 1].second - events[0].first, currD, resD = 1, i, currCoord, nextCoord;
	int coinsLeft, activeIntervals;
	//Event currOpeningEvent;
	//Event currClosingEvent;

	while (minD <= maxD) {
		currD = minD + (maxD - minD) / 2;
		coinsLeft = n - 1;
		i = 0;
		currCoord = events[0].first;
		//activeIntervals = 1;
		//currOpeningEvent = events[0];
		//currOpeningEvent = events[1];

		while (i < m && coinsLeft > 0) {
			nextCoord = currCoord + currD;

			while (i < m && nextCoord > events[i].second) {
				++i;
			}

			if (i < m) {
				nextCoord = max(nextCoord, events[i].first);

				--coinsLeft;
				currCoord = nextCoord;
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