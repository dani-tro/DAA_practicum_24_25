#include <bits/stdc++.h>

using namespace std;

#define MAX 310000

long long n, m, w[MAX], h[MAX], x[MAX], y[MAX], sum, ans, idx;

struct point
{
    long long x, y;
    bool operator<(const point& other) const
    {
        return x < other.x;
    }
};

vector<point> points;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> h[i];
    }
    
    for(int i = 0; i < m; i++)
    {
        cin >> x[i] >> y[i];
        points.push_back({x[i], y[i]});
    }
    
    sort(points.begin(), points.end());
    
    for(auto p : points)
    {
        while(idx < n && p.x > sum)
        {
            sum += w[idx++];
        }
        
        if(p.x > sum)continue;
        if(p.x == sum)
        {
            ans += (p.y <= max(h[idx - 1], h[idx]));
        }
        else
        {
            ans += (p.y <= h[idx - 1]);
        }
    }
    cout << ans << endl;
    
    return 0;
}

