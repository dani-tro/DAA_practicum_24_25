#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

struct water {
	long long cont;
	long long tub;
};

bool cmp(water a, water b) {
	return a.cont / a.tub < b.cont / b.tub;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	long long n, k;

	cin >> n;
	cin >> k;

	water* a = new water[n];

	for (int i = 0; i < n; i++) {
		long long c, t;
		cin >> c;
		cin >> t;
		a[i].cont = c;
		a[i].tub = t;
	}

	sort(a, a + n, cmp);

	int count_water = 0;
	int count_time = 0;
	int i = 0;

	while (count_time <= k) {
		if (i == n) {
			i = 0;
		}
		long long m = a[i].cont % a[i].tub;
		long long p = a[i].cont / a[i].tub;
		if (p > k - count_time) {
			count_water += a[i].tub * (k - count_time);
			break;
		}
		count_water += a[i].cont - m;
		count_time += p;
		if (i < n - 1 && a[i].cont - m > a[i + 1].tub && count_time < k) {
			count_water += a[i].cont - m;
			count_time += 1;
		}
	}

	cout << count_water;

	delete[] a;

	return 0;
}