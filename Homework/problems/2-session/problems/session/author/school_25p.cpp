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
std::priority_queue <std::pair <llong,int>> pq;
int freeLessons;

bool check(llong value)
{
    llong freeLessonsB = m * n;
    for (int i = 1 ; i <= n && freeLessonsB >= 0 ; ++i)
    {
        freeLessonsB -= value / a[i] + ((value % a[i]) > 0);
    }
 
    return freeLessonsB >= 0;
}
 
void solve()
{
    freeLessons = n * m;
    for (int i = 1 ; i <= n ; ++i)
    {
        pq.push({0, i});
    }

    while (freeLessons > 0)
    {
        auto [val, idx] = pq.top();
        pq.pop();

        freeLessons--;
        pq.push({val - a[idx], idx});
    }

    std::cout << -pq.top().first << '\n';
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