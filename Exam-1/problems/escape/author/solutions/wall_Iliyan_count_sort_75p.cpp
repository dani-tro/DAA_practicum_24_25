#include<iostream>
#include<vector>
#define MAXL 1000000
#define MAXN 100000
using namespace std;
vector <int> cnt[MAXL+1];
int h[MAXN],l[MAXN];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int k,ans=0;
    int n,maxl=0;
    cin >> n >> k ;
    for (int i=0; i<n; i++) {
        cin >> h[i] >> l[i] ;
        cnt[l[i]].push_back(i);
        maxl=max(maxl,l[i]);
    }
    int num;
    for (int i=maxl; i>=1; i--) {
        for (auto ind : cnt[i]) {
            if (i==l[ind]) num=h[ind]/l[ind];
            else num=1;
            ans+=i*min((long long int)num,k);
            k-=num;
            if (k<0) break;
            if ((i==l[ind])&&(h[ind]%l[ind]!=0)) cnt[h[ind]%l[ind]].push_back(ind);
        }
        if (k<0) break;
    }
    cout << ans ;
    cout << endl ;
    return 0;
}
