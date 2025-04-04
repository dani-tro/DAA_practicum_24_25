#include<bits/stdc++.h>
using namespace std;
long long a[200005],n, l, ans=0,MAX;
int main(){
    int i,j;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //a[n]=1e15;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ans=l=1;
    for(i=2;i<=n;i++){
        while(l<i && a[l]+a[l+1]<=a[i]) l++;
        ans=max(ans,i-l+1);
    }

    cout<<ans<<endl;
    return 0;
}

