#include <bits/stdc++.h>
using namespace std;

long n, k;

vector<unsigned> tubes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;

    for (long i = 0; i < n; ++i) {
        unsigned l, t;
        cin >> l >> t;
        for (unsigned j = 0; j < l / t; ++j) {
            tubes.push_back(t);
        }
        if (l % t > 0) {
            tubes.push_back(l % t);
        }
    }

    sort(tubes.begin(), tubes.end());

    long result = 0;

    long maxT = 0;
    if (tubes.size() - k > 0) {
        maxT = tubes.size() - k;
    }

    for (long i = tubes.size()-1; i >= maxT; --i) {
        result += tubes[i];
    }

    cout << result;
    return 0;
}