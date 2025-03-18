#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e2 + 10;
long long a[MAXN];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    long long sum = 0;
    for (int i = 0; i < m; i++) sum -= a[i];
    for (int i = m; i < n; i++) sum += a[i];
    cout << sum << endl;
    return 0;
}