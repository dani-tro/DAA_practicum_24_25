# include <bits/stdc++.h>
using namespace std;


struct interval{
    long long l;
    long long r;

    bool operator<(const interval& other){
        return l < other.l;
    }
};


const long maxn = 1e6 + 2;
long N, m, idx;
interval a[maxn];


bool check(long long mid, long long n){
    long long curr = a[1].l;
    --n;
    for(long long i = 1; i <= m; ++i){
        if(i >= 2 && curr + mid <= a[i].l){
            curr = a[i].l;
            --n;
        }
        while((curr + mid <= a[i].r) && n > 0){
            curr += mid;
            --n;
        }
        if(n == 0) return true;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> m;
    for(long i = 1; i <= m; ++i){
        cin >> a[i].l >> a[i].r;
    }

    sort(a + 1, a + m + 1);

    long long l = 1, r = 2e18, mid;
    while(l < r){
        mid = (l+r) / 2;
        // cout << l << " " << mid << " " << r << endl;
        if(check(mid, N)){
            if(l == mid) break;
            l = mid;
        } else r = mid;
    }
    cout << l << endl;
}