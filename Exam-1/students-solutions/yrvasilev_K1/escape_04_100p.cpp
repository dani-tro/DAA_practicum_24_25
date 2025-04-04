#include<bits/stdc++.h>
using namespace std;
long long m,n, l,r,mid, ans=0,MAX, t1, t2, mn, cr, br;
pair <long long, long long> a[200005];
int main(){
    int i,j;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //a[n]=1e15;
    br=0;
    cin>>n>>m;
    for(i=0;i<n;i++) {
        cin>>t1>>t2;
        a[br++]={-t2,t1/t2};
        a[br++]={-(t1%t2),1};
    }
    sort(a,a+br);
    // for(i=0;i<br;i++){
    //     cout<<-a[i].first<<" "<<a[i].second<<endl;
    // }
    for(i=0;i<br && m>0;i++){
        t1=min(m,a[i].second);
        ans-=a[i].first*t1;
        m-=t1;
    }
    cout<<ans<<endl;
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