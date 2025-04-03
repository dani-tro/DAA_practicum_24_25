# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
long long a[maxn], n, k;
long long check(long long d)
{
    int pos = 1;
    int count = 0;
    while (pos <= n)
    {
        int k = pos;
        while(k < n && a[k+1]-a[pos] <= d) k++;
        count ++;
        pos = k;
        while(k < n && a[k+1]-a[pos] <= d) k++;
        pos = k + 1;
    }
    return count;
}
int main()
{
    cin >> n >> k;
    int i;
    int x;
    a[1] = 0;
    for(i = 2; i <= n; i++){
        cin >> x;
        a[i] = a[i-1] + x;
    }
    long long l = 0, r = 1e14, mid;
    while (l < r)
    {
        mid = (l+r)/2;
        if(check(mid) > k) l = mid + 1;
        else
            r = mid;
    }
    cout << l << endl;
}