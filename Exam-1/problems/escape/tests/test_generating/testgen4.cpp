#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <time.h>
using namespace std;
const int maxn = 2e6+10, maxk = 1e6+10;

int n, maxl, maxh;
long long k;

struct sector {

    int h, l;
    inline friend bool operator > (sector a, sector b) {

        return a.l > b.l;

    }

} wall[maxn];

priority_queue < int > remainders;

void build_array() {

    // cout << "curr: " << (maxl - 9*maxl/10 + 1) << ' ' << maxh << '\n'; 
    for (int i = 1 ; i <= n ; ++i) {

        wall[i].l = rand()%3+1;
        wall[i].h = rand()%(maxh - 9*maxh/10) + 9*maxh/10;

    }

    sort(wall+1, wall+1+n, greater <sector>());


}

void sorted() {

    for (int i = 1 ; i < n ; ++i)
        assert(!(wall[i+1] > wall[i]));

}

void constraints() {
    
    assert(1 <= n && n <= 100000);
    for (int i = 1 ; i < n ; ++i) {
    
        assert(1 <= wall[i].l && wall[i].l <= maxl);
        assert(1 <= wall[i].h && wall[i].h <= maxh);
    
    }

}


vector < long long > possible;

void calc_k() {

    // cout << "walls: \n";
    // cout << n << '\n';
    // for (int i = 1 ; i <= n ; ++i)
    //     cout << wall[i].h << ' ' << wall[i].l << '\n';

    sorted();
    constraints();
    while (!remainders.empty()) remainders.pop();

    possible.push_back(0);
    sort(wall+1, wall+1+n, greater <sector> ());

    for (int i = 1 ; i <= n ; ++i) {

        int top = 0;
        if (!remainders.empty()) top = remainders.top();
        if (top >= wall[i].l) {

            --i;
            possible.push_back(possible.back()+1);
            if (!remainders.empty()) remainders.pop();
            
        } else {

            possible.push_back(possible.back() + wall[i].h / wall[i].l);
            remainders.push(wall[i].h % wall[i].l);

        }

    }

    // cout << "possible:\n";
    // for (int i = 0 ; i < possible.size() ; ++i)
    //     cout << possible[i] << ' ';
    // cout << '\n';

    while (!remainders.empty()) {
        
        possible.push_back(possible.back()+1);
        remainders.pop();

    }

    int ix = possible.size()-1 - min((int)possible.size()-1, rand()%min((int)sqrt(n), 5));
    k = possible[ix];

}

ofstream fout;
void build() {

    ifstream fin("constraints.txt");

    int min_n, max_n;
    fin >> min_n >> max_n;
    fin >> maxl >> maxh;

    n = rand()%(max_n - min_n + 1) + min_n;

    cout << "to build array\n";

    build_array();

    cout << "to calc_k\n";

    calc_k();

    cout << "to shuffle\n";

    random_shuffle(wall+1, wall+1+n);

    fout << n << ' ' << k << '\n';
    for (int i = 1 ; i <= n ; ++i) 
        fout << wall[i].h << ' ' << wall[i].l << '\n';
    
}

int main (int argc, char** argv) {

    srand(time(nullptr));

    if (argc != 2) {

        cout << "There should be exactly one argument - the name of the in file!\n";
        return 0;

    }

    fout.open(argv[1]);
    build();
    
    return 0;

}