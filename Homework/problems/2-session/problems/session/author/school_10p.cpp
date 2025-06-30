#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
 
typedef long long llong;
const int MAXN = 300000 + 10;
const llong INF = 1e18;
 
int n, m;
llong a[MAXN]; 
llong b[MAXN];

void solve()
{
    llong res = INF;
    for (int i = 1 ; i <= n ; ++i)
    {
        res = std::min(res, std::max(a[i], b[i]));
    }

    std::cout << res << '\n';
}
 
void read()
{
    std::cin >> n >> m;
    for (int i = 1 ; i <= n ; ++i) 
    {
        std::cin >> a[i];
    }
 
    for (int i = 1 ; i <= n ; ++i) 
    {
        std::cin >> b[i];
    }
}
 
void fastIO()
{
    std::ios_base :: sync_with_stdio(0);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
}
 
int main()
{
    fastIO();
    read();
    solve();
 
    return 0;
}