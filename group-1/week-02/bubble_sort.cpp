#include <iostream>
using namespace std;

const int MAXN = 1e3 + 10;

int a[MAXN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (a[j - 1] > a[j]) swap(a[j - 1], a[j]);
        }
        for (int j = 0; j < n; j++) cout << a[j] << ' ';
        cout << '\n';
    }
    return 0;
}