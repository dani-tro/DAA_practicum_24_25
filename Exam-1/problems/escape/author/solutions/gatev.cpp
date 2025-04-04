#include<bits/stdc++.h>
#define MAXN 100007
using namespace std;
long long h[MAXN],l[MAXN],k,ans,n;
vector< pair<long long,long long> > v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i]>>l[i];
        if(h[i]/l[i]>0)v.push_back({l[i],h[i]/l[i]});
        if(h[i]%l[i]>0)v.push_back({h[i]%l[i],1});
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size() and k>=1;i++){
        ans+=v[i].first*min(k,v[i].second);
        k-=v[i].second;
    }
    cout<<ans<<"\n";
    return 0;
}
