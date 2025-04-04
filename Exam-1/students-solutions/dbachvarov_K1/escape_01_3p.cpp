#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct s
{
    long long big;
    long long small;
};

bool cmp(const s& s1, const s& s2)
{
    if (s1.small > s2.small)
        return true;
    return s1.big > s2.big;
}

#define MAXN 100010

long long n, k;
s rooms[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> rooms[i].big >> rooms[i].small;
    }

    sort(rooms, rooms+n, cmp);
    long long result = 0; int j = 0;

    for (int i = 0; i <= k; i++)
    {
        if (rooms[j].big >= rooms[j].small)
        {
            rooms[j].big -= rooms[j].small;
            result += rooms[j].small;
        }
        else
        {
            if (rooms[j].big > rooms[j + 1].small)
            {
                result += rooms[j].big;
                rooms[j].big = 0;
                j++;
            }
            else
            {
                j++;
                rooms[j].big -= rooms[j].small;
                result += rooms[j].small;
            }
        }

        //cout << result << " " << i << endl;
    }

    cout << result << endl;
}