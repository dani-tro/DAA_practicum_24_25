#include <bits/stdc++.h>
using namespace std;

mt19937 myrand(243613443);

//const int MAXN = 2e6 + 10;
void quick_sort(vector <int>& a) {
    if (a.size() <= 1) return;

    vector <int> low, high, eq;
    int n = a.size();
    int pivot = a[myrand() % n];

    for (auto i : a) {
        if (i < pivot) low.push_back(i);
        else if (i == pivot) eq.push_back(i);
        else high.push_back(i);
    }

    quick_sort(low);
    quick_sort(high);

    int ptr = 0;
    for (auto i : low) {
        a[ptr] = i;
        ptr++;
    }
    for (auto i : eq) {
        a[ptr] = i;
        ptr++;
    }
    for (auto i : high) {
        a[ptr] = i;
        ptr++;
    }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    quick_sort(a);

    for (auto i : a) cout << i << ' ';
}