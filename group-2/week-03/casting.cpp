# include <bits/stdc++.h>
using namespace std;
struct singer{
    int arr, dur;
};
const int maxn = 10005;
singer a[maxn];
bool cmp(singer i, singer j)
{
    // if (i.arr < j.arr) return true;
    // if (i.arr > j.arr) return false;
    // return i.dur >= j.dur;
    ///////////////////////////////////
    return i.arr < j.arr || (i.arr == j.arr && i.dur >= j.dur);
    ///////////////////////////////////
    // if (i.arr == j.arr) return i.dur >= j.dur;
    // return i.arr < j.arr;
}
int studio[maxn], n;
int get_studio(int t)
{
    int mint = 1e9;
    int idx;
    for(int i = 0; i < n; i++)
    {
        int currt;
        if (studio[i] <= t) currt = t;
            else
                currt = studio[i];
        if (mint > currt)
        {
            mint = currt;
            idx = i;
        }
    }
    return idx;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> a[i].arr >> a[i].dur;
    sort(a,a+m,cmp);
    for (int i = 0; i < m; i++)
    {
        int k = get_studio(a[i].arr);
        studio[k] = max(a[i].arr,studio[k]) + a[i].dur;
    }

    int ans = 0, ansid;
    for (int i = 0; i < n; i++)
    {
        if (ans <= studio[i])
        {
            ans = studio[i];
            ansid = i;
        }
    }
        

    cout << ans << " " << ansid+1 << endl;
}