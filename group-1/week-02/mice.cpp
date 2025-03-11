#include <iostream>
using namespace std;

const int MAXN = (1 << 19) + 10;

int a[MAXN], temp[MAXN];
long long find_ans(int l, int r) {
    if (l == r) return 0;

    int mid = (l + r) / 2;
    long long s1 = find_ans(l, mid);
    long long s2 = find_ans(mid + 1, r);

    int ptr1, ptr2;
    long long sum1, sum2;
    ptr1 = l;
    ptr2 = mid + 1;
    sum1 = sum2 = 0;
    for (int i = l; i <= r; i++) {
        if (ptr1 > mid) {
            temp[i] = a[ptr2];
            sum2 += ptr1 - l;
            ptr2++;
            continue;
        }
        if (ptr2 > r) {
            temp[i] = a[ptr1];
            sum1 += ptr2 - mid - 1;
            ptr1++;
            continue;
        }
        if (a[ptr1] < a[ptr2]) {
            temp[i] = a[ptr1];
            sum1 += ptr2 - mid - 1;
            ptr1++;
        } else {
            temp[i] = a[ptr2];
            sum2 += ptr1 - l;
            ptr2++;
        }
    }

    for (int i = l; i <= r; i++) a[i] = temp[i];

    return s1 + s2 + min(sum1, sum2);
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k, n;
    cin >> k;
    n = (1 << k);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << find_ans(0, n-1) << endl;
    return 0;
}