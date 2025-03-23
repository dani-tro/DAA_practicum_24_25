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
event a[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[n+i].x;
        a[i].state = 1;
        a[n+i].state = -1;
    }
    sort(a+1,a+2*n+1);
    int segs = 0;
    int maxseg = 0;
    int sum = 0;
    int start = a[1].x;
    for(int i = 1; i <= 2*n; i++)
    {
        sum += a[i].state;
        if (sum == 0) {segs++; maxseg = max(maxseg, a[i].x-start);}
        else
            if (a[i].state == 1 && sum == 1) start = a[i].x;
    }
    cout << segs << " " << maxseg << endl;
}