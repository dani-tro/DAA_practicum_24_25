#include <bits/stdc++.h>
using namespace std;

mt19937 myrand(773131746);

int pick(vector <int>& a, int k) {
    int n = a.size();
    int pivot = a[myrand() % n];

    vector <int> low, high, eq;
    for (auto i : a) {
        if (i < pivot) low.push_back(i);
        else if (i == pivot) eq.push_back(i);
        else high.push_back(i);
    }
    if (low.size() >= k) return pick(low, k);
    k -= low.size();
    if (eq.size() >= k) return pivot;
    k -= eq.size();
    return pick(high, k);
}
int findKthLargest(vector <int>& a, int k) {
    return pick(a, a.size() - k + 1);
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << findKthLargest(a, k) << endl;
    return 0;
}