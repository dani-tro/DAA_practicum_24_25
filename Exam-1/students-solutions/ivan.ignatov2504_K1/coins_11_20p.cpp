#include <bits/stdc++.h>

#define llong long long

const llong MAXSIZE = 1e9;

int n, m;

llong minBeg = MAXSIZE, maxEnd = -1;

std::vector<llong> boards; 

bool check(llong d) {
    llong leftDist = 0;
    llong lastEnd = 0;

    llong res = 0;

    for(int i = 0; i < 2 * m - 1; i += 2) {
        llong start = boards[i];
        llong end = boards[i + 1];

        // if(leftDist > start - lastEnd) {
        //     llong oldStart = start;
        //     llong diff = leftDist - (start - lastEnd);
        //     start += diff;
        //     leftDist -= oldStart - lastEnd;
        // }

        // if(start > end) {
        //     leftDist -= (start - lastEnd); 
        //     lastEnd = end;
        //     continue;
        // }

        if(leftDist > start - lastEnd) {
            leftDist -= start - lastEnd;
            start += leftDist;
        }

        if(start > end) {
            lastEnd = end;
            continue;
        }

        res += (end - start) / d;
        leftDist = (end - start) % d;
        if(leftDist > 0) {
            ++res;
        }
        lastEnd = end;
    }

    return res >= n;
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
    }

    std::sort(boards.begin(), boards.end());

    llong l = 1, r = maxEnd / n + 1;

    while(l < r) {
        llong d = (l + r) / 2;

        if(check(d)) {
            l = d + 1;
        } else {
            r = d;
        }
    }

    std::cout << l << std::endl;
}