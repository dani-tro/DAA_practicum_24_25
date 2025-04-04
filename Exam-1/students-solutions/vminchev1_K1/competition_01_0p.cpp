
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int lin;
vector<lin> x;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    lin n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        lin num;
        cin >> num;
        x.push_back(num);
    }
    sort(x.begin(), x.end());
    lin l = 0;
    lin r = n;
    while (l < r) {
        lin mid = (l + r + 1) / 2;
        if (x[0] + x[1] <= x[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
    }
    cout << l + 1;
}
