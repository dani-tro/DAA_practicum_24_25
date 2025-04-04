#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int h, l; cin >> h >> l;
        v.push_back({l, h/l});
        v.push_back({h%l, 1});
    }
    sort(v.begin(), v.end());

    long long ans = 0;
    for (int i = v.size()-1; i >= 0; i--) {
        ans += v[i].first*(min(v[i].second, k));
        k -= min(v[i].second, k);
    }
    cout << ans << endl;

    return 0;
}
