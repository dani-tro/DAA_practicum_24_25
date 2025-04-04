#include <bits/stdc++.h>
using namespace std;


struct room{
    long long l;
    long long t;
    long long cap;

    bool operator>(const room& other) const{
        return cap < other.cap;
    }
};

const long long maxn = 1e7 + 3;
long long n, k;
room doors[maxn];
priority_queue<room, vector<room>, greater<room>> pq;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for(long long i = 1; i <= n; ++i){
        cin >> doors[i].l >> doors[i].t;
        doors[i].cap = min(doors[i].t, doors[i].l / 2);
        pq.push(doors[i]);
    }

    long long liters = 0;
    for(long long i = 1; i <= k; ++i){
        room door = pq.top();
        liters += door.cap;
        pq.pop();
        door.l -= door.cap;
        door.cap = min(door.t, door.l / 2);
        pq.push(door);
    }

    cout << liters << endl;

    return 0;
}