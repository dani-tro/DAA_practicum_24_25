#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int lin;
vector<lin> x;
vector<lin> l;
vector<lin> t;
vector<pair<lin, bool>> planks;

//

int main() //1
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
	lin tar = 7;
    while (l < r) {
        lin mid = (l + r + 1) / 2;
        if (x[0] + x[1] >= x[mid])
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l + 1;
}
