#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
 
typedef long long llong;
const int MAXN = 300000 + 10;
const llong INF = 1e18;
 
llong n, m;
llong a[MAXN]; 
llong b[MAXN];

bool check(llong value)
{
    llong freeB = m * n;
    for (int i = 1 ; i <= n && freeB >= 0 ; ++i)
    {
        freeB -= value / a[i] + ((value % a[i]) > 0);
    }
 
    return freeB >= 0;
}
 
void solve()
{
    llong l = 0, r = INF + 1, mid;
    while (l < r - 1)
    {
        mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
 
    std::cout << l << '\n';
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
        a[i] = std::max(a[i], b[i]);
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