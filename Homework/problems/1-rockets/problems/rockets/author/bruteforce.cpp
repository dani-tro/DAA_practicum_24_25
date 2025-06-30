#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TVBox {
    long long left, right, height;
};

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<TVBox> tvs(n);
    vector<pair<long long, long long>> bullets(m);
    
    long long currentX = 0;
    for (int i = 0; i < n; ++i) {
        long long width, height;
        cin >> width >> height;
        tvs[i].left = currentX;
        tvs[i].right = currentX + width;
        tvs[i].height = height;
        currentX += width;
    }

    for (int i = 0; i < m; ++i) {
        cin >> bullets[i].first >> bullets[i].second;
    }

    int hitCount = 0;
    for (const auto& bullet : bullets) {
        long long x = bullet.first;
        long long y = bullet.second;

        for (int i = 0; i < n; i++) {
        	auto tv = tvs[i];
            if (x >= tv.left && x <= tv.right && y <= tv.height) {
                hitCount++;
                break;
            }
        }
    }

    cout << hitCount << endl;

    return 0;
}

