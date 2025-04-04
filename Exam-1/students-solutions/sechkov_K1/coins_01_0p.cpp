#include <bits/stdc++.h>
using namespace std;

struct coord {
	long long one;
	long long two;
};

bool cmp(coord a, coord b) {
	return a.one > b.one;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	long long n, m;

	cin >> n;
	cin >> m;

	coord* a = new coord[m];

	long long sum = 0;

	for (int i = 0; i < m; i++) {
		cin >> a[i].one;
		cin >> a[i].two;

		if (a[i].one > a[i].two) {
			long long temp = a[i].one;
			a[i].one = a[i].two;
			a[i].two = temp;
		}

		sum += a[i].two - a[i].one + 1;
	}

	sort(a, a + m, cmp);

	long long length = a[m - 1].two - a[0].one;

	long long r = length / n;
	long long l = 0;

	while (l < r) {
		long long mid = (l + r) / 2;
		long long count = n - 1;
		long long last_place = a[0].one;
		int i = 0;
		while (count > 0 && last_place + mid < length && i < m) {
			if (last_place + mid <= a[i].two && last_place + mid >= a[i].one) {
				last_place += mid;
				count--;
			}
			else {
				i += 1;
			}
		}
		if (count > 0) {
			r = mid - 1;
		}
		else {
			l = mid;
		}
	}

	cout << l;

	delete[] a;

	return 0;
}