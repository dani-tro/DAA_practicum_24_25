# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int a[maxn];
int dp1[maxn], dp2[maxn];
int main()
{
    int n;
    cin >> n;
    int i;
    for(i = 1; i <= n; i++) cin >> a[i];
    dp1[1] = a[1];
    dp2[1] = a[1];
    dp1[2] = a[1]+a[2];
    dp2[2] = -INT_MAX/2;
    for(i = 2; i <= n; i++)
    {
        dp1[i] = max(dp1[i-1],dp2[i-1])+a[i];
        dp2[i] = dp1[i-2]+a[i];
    }
    int ans = -INT_MAX;
    for(i = 1; i <= n; i++)
    {
        ans = max({ans,dp1[i],dp2[i]});
    }
    cout << ans << endl;
}