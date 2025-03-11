#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int a[MAXN], b[MAXN];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    int ptrA, ptrB;
    ptrA = ptrB = 0;

    while (ptrA < n || ptrB < m) {
        if (ptrA == n) {
            cout << b[ptrB++] << ' ';
            continue;
        }
        if (ptrB == m) {
            cout << a[ptrA++] << ' ';
            continue;
        }

        if (a[ptrA] < b[ptrB]) cout << a[ptrA++] << ' ';
        else cout << b[ptrB++] << ' ';
    }
    cout << endl;
    return 0;
}