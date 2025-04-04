#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5;
const ll MAX_DIST = (ll)1e18 + 1;

int n, m;

struct gr
{
    ll l, r;

    inline ll len() const { return r - l;}
};

gr gredi[N];


ll countMaxCoinsWith(ll dist)
{
    ll res = gredi[0].len() / dist + 1;
    ll last = gredi[0].l + (res - 1) * dist, next;
    for(int i = 1; i < n; ++i)
    {
        next = gredi[i].l >= last + dist ? gredi[i].l : last + dist <= gredi[i].r ? last + dist : -1;
        if(next == -1) continue;
        res += (gredi[i].r - next) / dist + 1;
        last = next + (gredi[i].r - next) / dist * dist;
    }

    return res;
}

bool isPossible(ll dist)
{
    return countMaxCoinsWith(dist) >= n;
}

ll binarySearch()
{
    ll l = 1, r = MAX_DIST, mid;
    while(r - l > 1)
    {
        mid = l + ((r - l) >> 1);
        if(isPossible(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);


    cin >>n >>m;
    for(int i= 0; i < m; ++i)
    {
        cin >>gredi[i].l >> gredi[i].r;
    }

    sort(gredi, gredi + n, [](const gr a, const gr b){ return a.l < b.l;});

    cout << binarySearch() <<endl;
}
