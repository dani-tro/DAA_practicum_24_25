#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct Room
{
	long long l;
	long long t;
	bool operator <(const Room& other) const
	{
		return t > other.t || t == other.t && l > other.l;
	}
	bool operator >(const Room& other) const
	{
		return t < other.t || t == other.t && l < other.l;
	}
};
long long n, k;

bool cmp(Room r1, Room r2)
{
	return r1.t > r2.t || r1.t == r2.t && r1.l > r2.l;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	priority_queue<Room, vector<Room>, greater<Room>> pq;

	for (size_t i = 0; i < n; i++)
	{
		long long l, t;
		cin >> l >> t;
		pq.push({l, t});
	}
	long long totalSpill = 0;
	long long minutesPassed = 0;
	while (minutesPassed < k)
	{
		if (pq.top().t == 0)
			break;
		long long maxSpillTimes = pq.top().l / pq.top().t;
		if (k - minutesPassed >= maxSpillTimes)
		{
			totalSpill += maxSpillTimes * pq.top().t;
			minutesPassed += maxSpillTimes;
			Room r = pq.top();
			pq.pop();
			r.l -= maxSpillTimes * r.t;
			r.t = r.l;
			pq.push(r);
		}
		else
		{
			totalSpill += (k - minutesPassed) * pq.top().t;
			break;
		}
	}
	cout << totalSpill << endl;
	return 0;
}