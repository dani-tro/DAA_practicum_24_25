#include<bits/stdc++.h>
#define endl '\n'
 
using namespace std;
const int maxn = 1010;
 
int n, h[maxn], l[maxn], used[maxn];
long long k;

void solve()
{

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> h[i] >> l[i];

    long long ans = 0;
    for (int i = 1; i <= k; i ++)
    {
        int max_sum = 0, pos = -1;
        for (int j = 1; j <= n; j ++)
        {
            int best = max(0, min(l[j], h[j] - used[j] * l[j]));
            if (best > max_sum)
            {
                max_sum = best;
                pos = j;
            }
        }
        if (pos == -1)
            break;
        ans += max_sum;
        used[pos] ++;
    }
 
    cout << ans << endl;
 
}
 
int main()
{
    solve();
    return 0;
}