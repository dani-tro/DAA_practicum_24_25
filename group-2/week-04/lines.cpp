# include <bits/stdc++.h>
using namespace std;
struct event{
    int x;
    int state;
    bool operator<(const event& other) const
    {
        return x < other.x || (x==other.x && state > other.state);
    }
};
const int maxn = 2e6+5;
event a[maxn], b[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> b[i].x >> a[n+i].x >> b[n+i].x;
        if (a[i].x > a[n+i].x) swap(a[i].x, a[n+i].x);
        if (b[i].x > b[n+i].x) swap(b[i].x, b[n+i].x);
        a[i].state = 1;
        a[n+i].state = -1;
        b[i].state = 1;
        b[n+i].state = -1;
    }
    sort(a+1,a+2*n+1);
    sort(b+1,b+2*n+1);
    int sum = 0;
    int maxseg = 0;
    for(int i = 1; i <= 2*n; i++)
    {
        sum += a[i].state;
        maxseg = max(maxseg, sum);
    }
    for(int i = 1; i <= 2*n; i++)
    {
        sum += b[i].state;
        maxseg = max(maxseg, sum);
    }
    cout << maxseg << endl;
}