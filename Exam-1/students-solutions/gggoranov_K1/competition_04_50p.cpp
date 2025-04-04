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

    long long most = 0;

    for(int i = 1; i <= n - 1; ++i){
        long long curr_most = 0;
        for(int j = i+2; j <= n; ++j){
            if(x[i] + x[i+1] > x[j]) curr_most = j - i + 1;
                else
                    break;
        }
        most = max(most, curr_most);
    }

    cout << most << endl;
}