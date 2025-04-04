#include <iostream>
#include <queue>
using namespace std;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        long long l, t;
        cin>>l>>t;
        pq.push({l, t});
    }

    long long ans = 0;
    while(!pq.empty() && k > 0) {
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