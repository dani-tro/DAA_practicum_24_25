#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1e5+10;
int n;
long long k;

struct Room {
    long long l, t;

    bool operator<(const Room& other) const {
        return t < other.t;
    }
};
priority_queue<Room> pq;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        long long l, t;
        cin>>l>>t;
        pq.push({l, t});
    }

    long long ans = 0;
    while(k > 0) {
        Room curr = pq.top();
        pq.pop();
        if(k > curr.l / curr.t) {
            ans += curr.l / curr.t * curr.t;
            k-= curr.l / curr.t;
            curr.l = curr.l % curr.t;
            if(curr.l > 0) pq.push({curr.l, curr.l});
        }
        else {
            ans+= k * curr.t;
            break;
        }
    }

    cout<<ans<<endl;


    return 0;
}