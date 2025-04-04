#include <bits/stdc++.h>
using namespace std;

unsigned l[100005];
unsigned t[100005];
long n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;

    for (long i = 0; i < n; ++i) {
        cin >> l[i] >> t[i];
    }

    long result = 0;
    for (long i = 0; i < k; ++i) {
        long waterI = 0;

        for (long j = 1; j < n; ++j) {
            if (min(t[j], l[j]) > min(l[waterI], t[waterI])) {
                waterI = j;
            }
        }

        unsigned water = min(l[waterI], t[waterI]);
        l[waterI] -= water;
        result += water;
    }

    cout << result;
    return 0;
}