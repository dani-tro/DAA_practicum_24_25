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
room rms[N];

set<int> rem;

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

    sort(rms, rms + n, [](const room a, const room b)
         {
             return a.t == b.t ? a.l > b.l : a.t > b.t;
         });

    int mins, remain;
    ll liters;
    for(int i = 0; (i < n || !rem.empty()) && k > 0;)
    {
        mins = i < n ? min(k, (ll)(rms[i].l / rms[i].t)) : 0;
        liters = i < n ? mins * rms[i].t : 0;
        if(i < n && (rem.empty() || (-(*(rem.begin()))) <= liters))
        {
            res += liters;
            remain = rms[i].l % rms[i].t;
            if(remain > 0) rem.insert(-remain);
            //cout<<mins <<" minutes * " <<rms[i].t <<endl;
            k -= mins;
            ++i;
        }
        else if (!rem.empty() && (-(*(rem.begin()))) > liters)
        {
            //cout <<"Rem: "<<(-(*(rem.begin()))) <<endl;
            res += -(*(rem.begin()));
            rem.erase(rem.begin());
            --k;
        }
    }

    cout <<res <<endl;
}
