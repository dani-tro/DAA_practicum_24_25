#include<iostream>
#define MAXN 300000
using namespace std;
int a[MAXN],b[MAXN];
long long int round (long long int num, int den) {
    return (num%den==0)?num/den:num/den+1;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,m;
    cin >> n >> m ;
    for (int i=0; i<n; i++) {
        cin >> a[i] ;
    }
    for (int i=0; i<n; i++) {
        cin >> b[i] ;
        a[i]=max(a[i],b[i]);
    }
    long long int l=0,r=1e18,mid;
    r++;
    for (;;) {
        if (l==r-1) break;
        mid=(l+r)/2;
        long long int free=0;
        for (int i=0; i<n; i++) {
            if (round(mid,a[i])<=m) free+=m-round(mid,a[i]);
            else free-=(round(mid-m*a[i],b[i]));
            if (free+(n-i)*m<0) break;
        }
        if (free>=0) l=mid;
        else r=mid;
    }
    cout << l ;
    cout << endl ;
    return 0;
}
