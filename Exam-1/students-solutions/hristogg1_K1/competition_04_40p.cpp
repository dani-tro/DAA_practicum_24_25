#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long n;
unsigned long long students[200000];
unsigned long long pairs[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> students[i];

    std::sort(&students[0], &students[n]);

    for (int i = 0; i < n - 1; ++i)
        pairs[i] = students[i] + students[i + 1];
   

//    cout << endl;
//for (int i = 0; i < n; ++i)
//	cout << students[i]<<" ";
//
//
//    cout << endl;
//   for (int i = 0; i < n-1; ++i)
//   	cout << pairs[i]<<" ";


    int maxRes = 2;
    for (int i = n-1; i >= 2; --i) {
        for (int j = 0; j < n - 1; ++j) {
            if (pairs[j] > students[i]) {
                if (maxRes < i - j + 1)
                    maxRes = i - j + 1;
            }
        }
    }

    std::cout << maxRes;




    //cout << endl;
    //for (int i = 0; i < n; ++i)
    //	cout << students[i];
}