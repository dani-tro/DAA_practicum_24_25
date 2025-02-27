#include <bits/stdc++.h>

using namespace std;

#define MAX 10100

long long n, a[MAX], tmpsum, sum = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int k = 1; k <= n; k += 2)
    {
        tmpsum = 0;
        for(int i = 0; i < k; i++)tmpsum += a[i];
        sum += tmpsum;
        for(int i = 1; i < n - k + 1; i++)
        {
            tmpsum -= a[i - 1];
            tmpsum += a[i + k - 1];
            sum += tmpsum;
        }
    }

    cout << sum << endl;

    return 0;
}