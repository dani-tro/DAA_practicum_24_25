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

    //    cout << endl;
    //for (int i = 0; i < n; ++i)
    //	cout << students[i]<<" ";


    int maxRes = 2;
    for (int i = 1; i < n; ++i) {
        int l = i + 1, r = n;
        while (l != r) {
            int mid = (l + r) / 2;
            if (students[i] + students[i - 1] > students[mid]) {
                if (maxRes < mid - i + 2) {
                    maxRes = mid - i + 2;
                }
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
    }

    std::cout << maxRes;




    //cout << endl;
    //for (int i = 0; i < n; ++i)
    //	cout << students[i];
}