#include <bits/stdc++.h>

const int MAXN=201000;
int a[MAXN];
int n;
using namespace std;
bool b[MAXN];
bool cmp(int a, int b, int c){
      return a + b > c;
}
bool check(int a,int b,int c){
    return cmp(a,b,c) && cmp(a,c,b) && cmp(b,c,a);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);
    int ans=0;
    int l=0;
    int r=2;
    int mid=1;
    while(r <= n) {
        if(check(a[l],a[mid],a[r])){
             ans=max(ans,r-l+1);
             
        }else{
            while(!check(a[l],a[mid],a[r])){
                l++;
                mid++;
            }
            ans=max(ans,r-l+1);
        }
        r++;
        
    }
    cout<<"Otgovor:" <<ans<<endl;
   return 0;
}