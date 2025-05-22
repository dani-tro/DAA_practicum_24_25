# include <bits/stdc++.h>
using namespace std;
long long dp[1000005];
vector <int> c;
int main()
{
    int n, x;
    cin >> n >> x;
    c.resize(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        dp[i] = INT_MAX; // i
        for (auto p : c)
        {
            if (i - p < 0) continue;
            dp[i] = min(dp[i], dp[i - p] + 1);
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
}