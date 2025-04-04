#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int canWeFindKStudents(long long k, vector<long long> results) {
    std::sort(results.rbegin(), results.rend());
    long long maxResult = results[0];
    long long cnt = 1;
    for (size_t i = 1; i < results.size()-1; i++)
    {
        if (results[i] + results[i + 1] < maxResult) {
            maxResult = results[i];
        }
        else {
            cnt++;
        }

    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);
    long long N;
   
    cin >> N;
    vector<long long> results(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> results[i];
    }

    long long l = 0, r = N+1, ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (canWeFindKStudents(mid, results)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }


    }
    //cout << ans;
    cout << canWeFindKStudents(0, results);
    return 0;
}

