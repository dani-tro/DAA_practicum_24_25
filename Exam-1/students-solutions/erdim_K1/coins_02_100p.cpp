#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 10;
int n, m;
struct Greda {
    long long l, r;
    bool operator<(const Greda& other) const {
        return l < other.l;
    }
};
Greda a[MAXN];

bool check(long long d) {
    long long last = a[1].l;
    int cnt = 1;
    for(int i=1;i<=m;i++) {
        if(a[i].r < last + d) continue;
        long long beg = a[i].l;
        if(beg < last + d) beg = last + d;
        cnt += (a[i].r - beg) / d + 1;
        last = a[i].r - (a[i].r - beg) % d;
    }

    return cnt >= n;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        long long l, r;
        cin>>l>>r;
        a[i] = {l, r};
    }

    sort(a+1, a+m+1);

    long long l = 0, r = 1e18;
    while(l <= r) {
        long long mid = (l + r)/2;
        if(check(mid)) {
            l = mid+1;
        }
        else {
            r = mid - 1;
        }
    }

    cout<<r<<endl;

    return 0;
}