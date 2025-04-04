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
    wall[1].l = rand()%(maxl - 9*maxl/10 + 1) + 9*maxl/10;
    wall[1].h = rand()%maxh+1;

    for (int i = 1 ; i < n ; ++i) {
        
        // cout << "wall[" << i << "] = " << wall[i].h << ' ' << wall[i].l << '\n';

        while (!remainders.empty() && remainders.top() >= wall[i].l) remainders.pop();
        remainders.push(wall[i].h % wall[i].l);

        if (rand()%2 && !remainders.empty() && 9*remainders.top()/10 >= 1) {
      
            // cout << i << ": pq: " << remainders.top() << "\n";
            wall[i+1].l = rand()%(remainders.top() - 9*remainders.top()/10 + 1) + 9*remainders.top()/10;
        
        } else {
            
            // cout << i << ": last:" << wall[i].l << ' ' << wall[i].l - 9*wall[i].l/10 << ' ' << 9*wall[i].l/10 << "\n";
            if (rand()%(int)10 == 0) wall[i+1].l = wall[i].l;
            if (wall[i].l >= 2) wall[i+1].l = rand()%(wall[i].l - max(1, 9*wall[i].l/10)) + max(1, 9*wall[i].l/10);
            else wall[i+1].l = 1;

        }

        if (rand()%10 == 0 && wall[i+1].l >= 2) wall[i+1].h = rand()%(wall[i+1].l-1)+1;
        else if (rand()%(int)10 == 0) wall[i+1].h = wall[i+1].l;
        else wall[i+1].h = rand()%(maxh - wall[i+1].l + 1) + wall[i+1].l;

    }

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

ofstream fout;
void build() {

    ifstream fin("constraints.txt");

    int min_n, max_n;
    fin >> min_n >> max_n;
    fin >> maxl >> maxh;
    n = max_n;
    k = n*(maxh/(maxl/1e5));

    fout << n << ' ' << k << '\n';
    for (int i = 1 ; i <= n ; ++i) 
        fout << maxh << ' ' << maxl/1e6 << '\n';
    
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