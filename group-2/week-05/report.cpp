# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, i;
    cin >> n;
    for(i = 1; i <= n; i++) cin >> a[i];
    stack <pair <int, int> > st;
    for(i = 1; i <= n; i++)
    {
        while(!st.empty() && st.top().first >= a[i]) st.pop();
        if (st.empty()) cout << 0 << " ";
        else
            cout << st.top().second << " ";
        st.push({a[i],i});
    }
    cout << endl;
}