# include <bits/stdc++.h>
using namespace std;


struct room{
    long long l;
    long long t;
    long long cap;

    bool operator<(const room& other) const{
        return (cap < other.cap) || (cap == other.cap && t < other.t);
        // return (t < other.t) || ((t == other.t) && (l < other.l));
    }
};

const long long maxn = 1e7 + 3;
long long n, k;
room doors[maxn];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for(long long i = 1; i <= n; ++i){
        cin >> doors[i].l >> doors[i].t;
        doors[i].cap = min(doors[i].t, doors[i].l / 2);
    }

    sort(doors + 1, doors + n + 1);

    long long liters = 0;
    for(long long i = 1; i <= k; ++i){

        liters += doors[n].cap;
        doors[n].l -= doors[n].cap;
        doors[n].cap = min(doors[n].t, doors[n].l / 2);
        sort(doors + 1, doors + n + 1);
    }

    cout << liters << endl;
}