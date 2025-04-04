#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

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
long long left[MAXN]; int l = 0;
s rooms[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int> pq;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> rooms[i].big >> rooms[i].small;
    }

    sort(rooms, rooms + n, cmp);

    long long result = 0;

    long long j = 0, i = 0;

    while (j < k && i < n)
    {
        while (j < k && !pq.empty() && pq.top() > rooms[i].small)
        {
            result += pq.top();
            pq.pop();
            j++;
        }

        if (j == k) break;

        int t = rooms[i].big / rooms[i].small;

        if (j + t >= k)
        {
            result += (k - j - 1) * rooms[i].small;
            break;
        } 

        result += t * rooms[i].small;
        j += t;

        if (rooms[i].big % rooms[i].small != 0)
            pq.push(rooms[i].big % rooms[i].small);

        i++;
    }

    cout << result << endl;
}