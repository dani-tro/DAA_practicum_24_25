# include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
long long t[maxn], l[maxn];
priority_queue<pair<long long, long long>> q;
int main()
{
    long long n, k, i, j;
    cin >> n >> k;
    assert (1 <= n && n <= 1e5);
    assert (1 <= k && k <= 1e14);
    for (i = 1; i <= n; i++)
    {
        cin >> l[i] >> t[i];
        assert (1 <= l[i] && l[i] <= 1e9);
        q.push({min(l[i], t[i]), l[i]});
    }
    long long ans = 0;
    long long x,y;
    char ch;
    assert (!(cin>>ch));
    while(!q.empty() && k > 0)
    {
        x = q.top().first;
        y = q.top().second;
        q.pop();
        long long whole = y/x;
        long long rem = y % x;
        if (rem != 0) q.push({rem, rem});
        ans += min(whole, k)*x;
        k -= min(whole, k);
    }

    cout << ans << endl;
        
    
}