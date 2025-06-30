# include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int maxS = 5e4+5;
long long dp[2][maxS];
int G[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> G[i];
    bool curr = 0;
    dp[curr][0] = 0;
    for(int i = 1; i <= maxS; i++)dp[curr][i] = INT_MAX;
    curr = !curr;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < maxS; j++)
        {
            dp[curr][j] = min({G[i]+dp[!curr][j], dp[!curr][abs(j-G[i])],(j+G[i] < maxS ? dp[!curr][j+G[i]] : INT_MAX)});
        }
        curr = !curr;
    }

    cout << dp[!curr][0] << endl;
}