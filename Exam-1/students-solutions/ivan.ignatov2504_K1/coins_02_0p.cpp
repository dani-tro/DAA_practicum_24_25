#include <bits/stdc++.h>

#define llong long long

const llong MAXSIZE = 1e9;

int n, m;

llong minBeg = MAXSIZE, maxEnd = -1;

std::vector<llong> boards; 

bool check(llong d) {
    // llong cnt = 0;
    // llong curr = minBeg;
    // llong left = n;
    // llong lastDist = d;

    // while(curr <= maxEnd && left > 0) {
    //     if(taken[curr] && lastDist >= d) {
    //         ++cnt;
    //         lastDist = 0;
    //         --left;
    //     }
    //     ++lastDist;
    //     ++curr;
    // }

    // return left == 0;
    llong leftDist = 0;
    llong lastEnd = 0;

    int res = 0;

    for(int i = 0; i < 2 * m; i += 2) {
        llong start = boards[i];
        llong end = boards[i + 1];

        if(start - lastEnd < leftDist) {
            start += leftDist;
        }

        if(start > end) {
            leftDist -= end;
            continue;
        }

        res += (end - start) / d + 1;
        llong lastCoin = start + (res - 1) * d;
        leftDist = std::max((long long)0, d - end + lastCoin);

        lastEnd = end;
    }

    return res > n;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin.tie(nullptr);
    
    std::cout.tie(nullptr);

    std::cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        llong li, ri;

        std::cin >> li >> ri;

        boards.push_back(li);
        boards.push_back(ri);

        if(ri > maxEnd) {
            maxEnd = ri;
        }

        // if(li < minBeg) {
        //     minBeg = li;
        // }

        // for (llong j = li; j <= ri; ++j)
        // {
        //     taken[j] = true;
        // }
    }

    std::sort(boards.begin(), boards.end());

    // for(llong num : boards) {
    //     std::cout << num << ' ';
    // }

    // std::cout << std::endl;

    llong l = 1, r = maxEnd;

    while(l < r) {
        llong mid = (l + r) / 2;

        if(check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    std::cout << l << std::endl;
}