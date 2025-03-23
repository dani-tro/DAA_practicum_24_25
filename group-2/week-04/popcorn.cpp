# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int n, k, s;
bool check(long long maxp)
{
    int cnt = 1;
    long long eat = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt > k) return false;
        if (eat + a[i] > maxp){
            cnt ++;
            eat = 0;
            i --;
        }
        else{
            eat += a[i];
        }
    }
    return true;
}
int main()
{
    cin >> n >> k >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    long long l = 1, r = 1e9, m;
    while(l < r)
    {
        m = (l+r)/2;
        long long maxp = m*s;
        if (check(maxp)) r = m;
            else
                l = m+1;
    }
    cout << l << endl;
}