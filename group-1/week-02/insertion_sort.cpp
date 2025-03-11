#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;

int a[MAXN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 2; i <= n; i++) {
        int elem = a[i];
        int j = i - 1;
        while (j > 0 && a[j] > elem) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = elem;
        for (int j = 1; j <= n; j++) cout << a[j] << ' ';
        cout << endl;
    }
    return 0;
}