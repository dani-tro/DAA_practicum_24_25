# include <bits/stdc++.h>
using namespace std;


const long long maxn = 1e6 + 2;
long long n, m, idx, L[maxn], R[maxn], a[maxn];


bool check(long long mid, long long n){
    long long curr = a[1];
    n--;
    for(int i = 1; i <= idx; ++i){
        if(a[i] - curr >= mid){
            curr = a[i];
            n--;
        }
        if(n == 0) return true;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    idx = 0;
    for(long long i = 1; i <= m; ++i){
        cin >> L[i] >> R[i];
        for(long long val = L[i]; val <= R[i]; ++val){
            a[++idx] = val;
        }
    }

    sort(a + 1, a + idx + 1);

    long long l = 1, r = a[idx] - a[1], mid;
    while(l < r){
        mid = (l+r) / 2;
        if(check(mid, n)) l = mid;
            else
                r = mid - 1;
    }
    cout << l << endl;

    return 0;
}