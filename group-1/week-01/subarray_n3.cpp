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
        for(int i = 0; i < n - k + 1; i++)
        {
            tmpsum = 0;
            for(int j = i; j < i + k; j++)
            {
                tmpsum += a[j];
            }
            sum += tmpsum;
        }
    }

    cout << sum << endl;

    return 0;
}