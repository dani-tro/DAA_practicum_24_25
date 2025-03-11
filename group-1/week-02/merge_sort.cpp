#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;

int res[20][MAXN], a[MAXN], maxLev;

void merge_sort(int l, int r, int level) {
    maxLev = max(maxLev, level);

    if (l == r) {
        res[level][l] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    merge_sort(l, mid, level + 1);
    merge_sort(mid + 1, r, level + 1);

    int ptrL, ptrR, br = l;
    ptrL = l;
    ptrR = mid + 1;

    while (ptrL <= mid || ptrR <= r) {
        if (ptrL > mid) {
            res[level][br++] = a[ptrR++];
            continue;
        }
        if (ptrR > r) {
            res[level][br++] = a[ptrL++];
            continue;
        }

        if (a[ptrL] < a[ptrR]) res[level][br++] = a[ptrL++];
        else res[level][br++] = a[ptrR++];
    }

    for (int i = l; i <= r; i++) a[i] = res[level][i];
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    merge_sort(0, n-1, 0);

    for (int i = 0; i <= maxLev; i++) {
        for (int j = 0; j < n; j++) cout << res[i][j] << ' ';
        cout << endl;
    }
    return 0;
}