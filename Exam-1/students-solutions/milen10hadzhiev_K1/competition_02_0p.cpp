#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n, l, r, result = 1, arr[200000];

int cond(int m) {
    int count = 0;
    for (int i = l; i < r; ++i) {
        if (arr[i] + arr[m] <= arr[r]) {
            return count;
        }
        count++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; ++i) {
        l = i;
        r = n;
        int mid;
        while (i <= r) {
            mid = (l + r) / 2;
            int curr = cond(mid);
            if (curr > result) {
                result = curr;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }
    cout << result;
    return 0;
}