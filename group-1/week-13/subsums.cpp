#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;
const int MAXS = 2e6 + 10;
const int offset = 1e6;

bool used[MAXS];
int a[MAXN];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector <int> sums, kop;
    sums.push_back(a[0] + offset);
    used[a[0] + offset] = true;

    for (int i = 1; i < n; i++) {
        for (auto s : sums) {
            if (!used[s + a[i]]) {
                used[s + a[i]] = true;
                kop.push_back(s + a[i]);
            }
        }
        for (auto s : kop) sums.push_back(s);
        kop.clear();

        if (!used[a[i] + offset]) {
            used[a[i] + offset] = true;
            sums.push_back(a[i] + offset);
        }
    }
    cout << sums.size() << endl;
}