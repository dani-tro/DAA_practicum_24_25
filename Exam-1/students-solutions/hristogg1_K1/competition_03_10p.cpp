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

    for (int i = n - 1; i >= 2; --i) {
        if (students[i] < (students[0] + students[1]))
        {
            std::cout << i + 1;
            return 0;
        }
    }

    std::cout << 2;




    //cout << endl;
    //for (int i = 0; i < n; ++i)
    //	cout << students[i];
}