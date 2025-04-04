#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long n, k;
std::pair<unsigned long long, unsigned long long> rooms[100000];

bool compare(std::pair<unsigned long long, unsigned long long> l, std::pair<unsigned long long, unsigned long long> r) {
    if (l.second < r.second)
        return true;
    else if (l.second == r.second)
        return l.first < r.first;
    else
        return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> rooms[i].first>>rooms[i].second;

    std::sort(&rooms[0], &rooms[n], compare);
    
    unsigned long long ind = n - 1, SUM = 0;
    while(k > 0){
        unsigned long long div = rooms[ind].first / rooms[ind].second, remainder = rooms[ind].first % rooms[ind].second;
            
        if (div == 0) {
            SUM += rooms[ind].first;
            rooms[ind].first = 0;
            k--;
            ind--;
            continue;
        }
        unsigned long long howManyTimes = min(div, k);
        unsigned long long toAdd = rooms[ind].second * howManyTimes;
        rooms[ind].first -= toAdd;
        SUM += toAdd;
        k -= howManyTimes;

    }
    cout << SUM;


    //cout << endl;
    //for (int i = 0; i < n; ++i)
    //	cout << students[i];
}