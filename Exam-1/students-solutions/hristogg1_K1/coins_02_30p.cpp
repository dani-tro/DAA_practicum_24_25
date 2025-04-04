#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long n, m;
std::pair<unsigned long long, unsigned long long> logs[100000];

bool isItPossible(int dist) {
    int lastPutPos = logs[0].first, put = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = logs[i].first; j <= logs[i].second; ++j) {
            if (j >= lastPutPos + dist) {
                lastPutPos = j;
                put++;
            }
        }
    }
    return put >= n;
}


bool compare(std::pair<unsigned long long, unsigned long long> l, std::pair<unsigned long long, unsigned long long> r) {
    return l.first < r.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> logs[i].first;
        cin >> logs[i].second;
    }

    std::sort(&logs[0], &logs[m], compare);

    //for (int i = 0; i < m; ++i) {
    //    std::cout << logs[i].first << " " << logs[i].second << endl;
    //}

    //cout << isItPossible(4);

    unsigned long long l = 1, r = logs[m - 1].second;
    while (l < r) {
        unsigned long long mid = (l + r) / 2;
        if (mid == l || mid == r) {
            cout << mid;
            return 0;
        }
        bool possible = isItPossible(mid);
        if (possible)
            l = mid;
        else
            r = mid;
    }
}