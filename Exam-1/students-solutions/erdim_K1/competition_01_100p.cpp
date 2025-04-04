#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN= 2e5+10;
int n;
int a[MAXN];

int main()
{ 
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }

    sort(a+1, a+n+1);

    int start = 1, ans = 1;
    for(int i=2;i<=n;i++){
        while(a[start] + a[start+1] <= a[i]) start++;
        ans = max(ans, i - start + 1);
    }

    cout<<ans<<endl;

    return 0;
}