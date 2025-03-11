#include <bits/stdc++.h>
using namespace std;

const int MAXK = 1e3 + 24;
int cnt[MAXK];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < cnt[i]; j++) cout << i << ' ';
    }
    cout << endl;
    return 0;
}