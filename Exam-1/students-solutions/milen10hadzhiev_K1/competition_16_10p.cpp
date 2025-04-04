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

    l = 0;
    r = n - 1;
    result = n;
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[l] + arr[mid] > arr[r]) {
            break;
        }
        result--;
        r--;
    }
    cout << result;
    return 0;
}
