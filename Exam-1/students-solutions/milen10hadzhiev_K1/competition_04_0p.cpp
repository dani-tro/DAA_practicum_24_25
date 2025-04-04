#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n, l, r, result = 1, arr[200000];

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
            if (arr[l] + arr[mid] < arr[r]) {
                l = mid + 1;
                result = mid;
            }
            else {
                r = mid - 1;
            }
        }
    }
    cout << result;
    return 0;
}