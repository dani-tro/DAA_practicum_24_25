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
        if (l % t > 0){
            tubes.push_back(l % t);}
    }

    sort(tubes.begin(), tubes.end());

    long result = 0;
    for (long i = tubes.size()-1; i >= tubes.size() - k; --i) {
        result += tubes[i];
    }

    cout << result;
    return 0;
}