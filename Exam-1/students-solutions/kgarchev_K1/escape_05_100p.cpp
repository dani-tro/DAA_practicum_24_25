#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5;

struct room
{
    int l, t;
};

int n;
ll k, res = 0;
room rms[N << 1];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >>n >>k;
    for(int i = 0; i < n; ++i)
    {
        cin >>rms[i].l >>rms[i].t;
    }
    for(int i = 0; i < n; ++i)
    {
        rms[i + n].l = rms[i].l % rms[i].t;
        rms[i + n].t  = rms[i + n].l > 0;
        rms[i].l /= rms[i].t;
        swap(rms[i].l, rms[i].t);
    } //l - litters per min, t - minutes

    n <<= 1;
    sort(rms, rms + n, [](const room a, const room b)
         {
             return a.l == b.l ? a.t > b.t : a.l > b.l;
         });

    int remain;
    ll mins, liters;
    for(int i = 0; i < n && k > 0; ++i)
    {
        mins = min(k, (ll)rms[i].t);
        res += mins * rms[i].l;
        k -= mins;
    }

    cout <<res <<endl;
}
