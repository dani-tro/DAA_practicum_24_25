#include<bits/stdc++.h>
using namespace std;
long long m,n, l,r,mid, ans=0,MAX, mn, cr, br;
pair <long long, long long> a[100005];
bool f(long long d){
    int i,j;
    br=mn=0;
    for(i=0;i<m;i++){
        mn=max(mn,a[i].first);
        if(a[i].second<mn) continue;
        cr=(a[i].second-mn)/d+1;
        br+=cr;
        mn+=cr*d;
    }
    return br>=n;
}

void solver(){
    l=0, r= 1e15;
    while(l<=r){
        mid=(l+r)/2;
        if(f(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
}
int main(){
    int i,j;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //a[n]=1e15;
    cin>>n>>m;
    for(i=0;i<m;i++) cin>>a[i].first>>a[i].second;
    sort(a,a+m);
    solver();
    //cout<<ans<<endl;
    return 0;
}

/*
5 3
9 9
4 7
0 2

8 3
1 6
10 15
7 10

5 3
1 6
10 15
7 10
*/
