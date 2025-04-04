#include <iostream>
#include <algorithm>
using namespace std;

const size_t maxsize = 1e5;


struct Room
{
	long long l;
	long long t;
};
Room rooms[maxsize];
long long n, k;

bool cmp(Room r1, Room r2)
{
	return r1.t > r2.t || r1.t == r2.t && r1.l > r2.l;
}

void fixRooms()
{
	long long i = 0;
	while (i < n && rooms[i].t < rooms[i + 1].t)
	{
		swap(rooms[i], rooms[i + 1]);
		++i;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for (size_t i = 0; i < n; i++)
	{
		cin >> rooms[i].l >> rooms[i].t;
	}
	sort(rooms, rooms + n, cmp);
	long long totalSpill = 0;
	long long minutesPassed = 0;
	long long currRoom = 0;
	while (minutesPassed < k)
	{
		if (rooms[currRoom].t == 0)
			break;
		long long maxSpillTimes = rooms[currRoom].l / rooms[currRoom].t;
		if (k - minutesPassed >= maxSpillTimes)
		{
			totalSpill += maxSpillTimes * rooms[currRoom].t;
			minutesPassed += maxSpillTimes;
			rooms[currRoom].l -= maxSpillTimes * rooms[currRoom].t;
			rooms[currRoom].t = rooms[currRoom].l;
			fixRooms();
		}
		else
		{
			totalSpill += (k - minutesPassed) * rooms[currRoom].t;
			break;
		}
	}
	cout << totalSpill << endl;
	return 0;
}