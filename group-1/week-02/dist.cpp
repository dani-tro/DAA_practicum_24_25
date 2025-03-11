#include <iostream>
using namespace std;

const int MAXN = 1e6 + 10;

int a[MAXN], b[MAXN];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ptrA, ptrB, ans;
    ptrA = ptrB = ans = 0;

    while (ptrA < n) {
        while (ptrB < n && b[ptrB] >= a[ptrA]) ptrB++;
        ans = max(ans, ptrB - ptrA - 1);
        ptrA++;
    }

    cout << ans << endl;
    return 0;
}
/*
9
8 8 4 4 4 3 3 3 1
9 9 8 8 6 5 5 4 3
*/