#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10;

long long a[MAXN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    long long sum, lef, ri, ans;
    sum = lef = ri = 0;
    ans = -1;
    
    while (lef < n) {
        while (ri < n && sum <= k) {
            sum += a[ri];
            if (sum <= k) ans = max(ans, sum);
            ri++;
        }
        sum -= a[lef];
        if (sum <= k && sum != 0) ans = max(ans, sum);
        lef++;
    }

    cout << ans << endl;
    return 0;
}