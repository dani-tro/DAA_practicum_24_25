#include <bits/stdc++.h>

using namespace std;
stack <int> st;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    while(cin >> x)
    {
        st.push(x);
    }

    while(!st.empty())
    {
        x = st.top();
        st.pop();
        double ans = sqrt(x);
        cout << fixed << setprecision(6) << ans << endl;
    }
}