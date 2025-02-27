#include <bits/stdc++.h>

using namespace std;
int calc(long long x)
{
    int res = 0;
    while(x != 0)
    {
        res += x%2; // res = res + x%2;
        x /= 2; // x = x / 2;
    }
    return res;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, x;
    cin >> n;
    int i;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        cout << calc(x) << endl;
    }
}