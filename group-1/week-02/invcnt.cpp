#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

int a[MAXN], sort_res[MAXN];

long long inversions(int l, int r) {

    if (l == r) {
        return 0;
    }

    int mid = (l + r) / 2;
    long long inv1 = inversions(l, mid);
    long long inv2 = inversions(mid + 1, r);

    int ptrL, ptrR, br;
    long long cur;
    cur = 0;
    ptrL = br = l;
    ptrR = mid + 1;

    while (br <= r) {
        if (ptrL > mid) {
            sort_res[br++] = a[ptrR++];
            continue;
        }
        if (ptrR > r) {
            cur += (long long) max(0, (ptrR - mid - 1));
            sort_res[br++] = a[ptrL++];
            continue;
        }

        if (a[ptrL] < a[ptrR]) {
            cur += (long long) max(0, (ptrR - mid - 1));
            sort_res[br++] = a[ptrL++];
        }
        else sort_res[br++] = a[ptrR++];
    }

    for (int i = l; i <= r; i++) a[i] = sort_res[i];

    return inv1 + inv2 + cur;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << inversions(0, n-1) << endl;
    return 0;
}