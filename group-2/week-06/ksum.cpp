# include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5+5;
long long a[maxn], b[maxn];
long long n, k;
long long count(long long target)
{
    long long pa = 1, pb = n;
    long long cnt = 0;
    for(pa = 1; pa <= n; pa++)
    {
        while(pb > 0 && a[pa] + b[pb] > target) pb --;
        cnt += pb;
    }
    return cnt;
}
int main()
{
    cin >> n >> k;
    long long i;
    for(i = 1; i <= n; i++) cin >> a[i];
    for(i = 1; i <= n; i++) cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    long long l = 1, r = 2e9, mid;
    while ( l < r)
    {
        mid = (l+r)/2;
        if(count(mid) < k) l = mid + 1;
            else
        r = mid;
    }
    cout << l << endl;

}