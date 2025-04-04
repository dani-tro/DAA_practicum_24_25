#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long n;
unsigned long long students[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> students[i];

    std::sort(&students[0], &students[n]);


    int maxRes = 2;
    for (int i = n-1; i >= 2; --i) {
        for (int j = 1; j < n; ++j) {
            if (maxRes == n)
            {
                cout << maxRes;
                return 0;
            }
            if (students[i] + students[i-1] > students[i]) {
                if (maxRes < i - j)
                    maxRes = i - j;
            }
        }
    }

    std::cout << maxRes;




    //cout << endl;
    //for (int i = 0; i < n; ++i)
    //	cout << students[i];
}