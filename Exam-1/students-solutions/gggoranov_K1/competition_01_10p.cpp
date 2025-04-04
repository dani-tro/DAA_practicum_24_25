# include <bits/stdc++.h>
using namespace std;


const long long maxn = 2e8 + 3;
long long n, x[maxn];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(long long i = 1; i <= n; ++i) cin >> x[i];

    sort(x + 1, x + n + 1);

    long long most_participants = 0;

    for(int i = 1; i <= n; ++i){
        
        long long l = 1, r = n, mid;
            while(l < r){
                mid = (l+r)/2;
                if(x[i] + x[i+1] <= x[mid]){
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
        most_participants = max(most_participants, l - i);
    }

    cout << most_participants << endl;

    return 0;
}