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

    for(int i = 0; i < n; i++)
    {
        sum += a[i] * (((i + 1) * (n - i) + 1) / 2);
    }

    cout << sum << endl;

    return 0;
}