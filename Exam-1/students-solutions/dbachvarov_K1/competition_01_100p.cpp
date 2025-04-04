#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 200000

long long n, x[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    sort(x, x + n);
    int l = 0;
    int cnt = 2, maxCnt = 2;

    for (int i = 2; i < n && l < n - 1; i++)
    {
        int curMin = x[l] + x[l + 1];

        if (curMin > x[i])
        {
            cnt++;
            maxCnt = max(cnt, maxCnt);
        }
        else
        {
            l++;
        }
    }

    cout << maxCnt << endl;
}