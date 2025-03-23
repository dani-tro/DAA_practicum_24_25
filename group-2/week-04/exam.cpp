# include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, f;
    cin >> n >> f;
    long long l = 1, r = sqrt(2*n), m;
    while (l < r)
    {
        m = (l+r)/2;
        long long sum = m*f + m*(m-1)/2;
        //cout << l << " " << r << " " << m << " " << sum << endl;
        if (sum < n) l = m+1;
            else
                r = m;
    }
    cout << l << endl;
}
