#include <bits/stdc++.h>

#define llong long long

const llong MAXSIZE = 1e5 + 20;

llong n, k;
std::priority_queue<std::pair<llong, llong>> queue;

// struct Room {
//     llong capacity;
//     llong tube;
//     llong times;
// };

// bool cmp(Room& r1, Room& r2) {
//     return r1.tube < r2.tube;
// }

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::cin.tie(nullptr);
    
    std::cout.tie(nullptr);
    
    std::cin >> n >> k;

    for (llong i = 0; i < n; ++i)
    {
        llong rem, size;
        std::cin >> rem >> size;
        queue.push({size, rem});
    }

    llong res = 0;

    for(llong i = 0; i < k; ++i) {
        // tube, rem
        std::pair<llong, llong> best = queue.top();
        queue.pop();
        res += best.first;
        best.second -= best.first;
        if (best.second == 0) {
            continue;
        }

        if (best.first > best.second) {
            best.first = best.second;
        }

        queue.push(best);
    }

    std::cout << res << std::endl;
}