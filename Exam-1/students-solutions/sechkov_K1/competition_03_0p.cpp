#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

long long n;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	long long* a = new long long[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	long long r = 2;
	long long l = 0;

	while (r < n) {
		if (a[r] >= a[l] + a[l + 1]) {
			l++;
		}
		r++;
	}

	cout << r - l + 1;

	delete[] a;

	return 0;
}