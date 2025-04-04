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
        for (int j = n - 1; j > i; --j) {
            if (students[i] + students[i - 1] > students[j]) {
                if (maxRes < j - i + 2) {
                    maxRes = j - i + 2;
                }
            }
        }
    }

    std::cout << maxRes;




    //cout << endl;
    //for (int i = 0; i < n; ++i)
    //	cout << students[i];
}