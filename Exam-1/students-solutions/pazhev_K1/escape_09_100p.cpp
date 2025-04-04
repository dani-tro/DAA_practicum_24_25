#include <bits/stdc++.h>
using namespace std;

long long n, k;

vector<pair<long long, long long>> tubes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;

    for (long long i = 0; i < n; ++i) {
        long long l, t;
        cin >> l >> t;  

        tubes.push_back({t, l / t});

        if (l % t > 0) {
            tubes.push_back({l % t, 1});
        }
    }

    sort(tubes.begin(), tubes.end());

    long long result = 0;
    long long count = 0;

    for (long long i = tubes.size()-1; i >= 0 && count < k; --i) {
        long long curr = tubes[i].second;

        if (count + curr > k) {
            curr = k - count;
        }

        result += tubes[i].first * curr;
        count += curr;
    }

    cout << result;
    return 0;
}