#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long n;
unsigned long long students[200000];


bool isItPossible(unsigned long long ans) {
    for (int i = 0; i < n - ans; ++i) {
        if (students[i] + students[i + 1] > students[i + ans - 1])
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> students[i];

    std::sort(&students[0], &students[n]);
    
    unsigned long long l = 2, r = n, best;
    while (l < r) {
        unsigned long long mid = (l + r) / 2;
        if (isItPossible(mid))
        {
            best = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << best;



    //cout << endl;
    //for (int i = 0; i < n; ++i)
    //	cout << students[i];
}