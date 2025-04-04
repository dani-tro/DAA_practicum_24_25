#include <bits/stdc++.h>
using namespace std;

void checkNoInput() {
    string s;
    assert(!getline(cin, s));
}

string readLine() {
    string s;
    assert(getline(cin, s));
    return s;
}

long long toLong(const string& s) {
    assert(s.size());
    assert(s.size() <= 18);
    long long ans = 0;
    for (char c: s) {
        assert(isdigit(c));
        ans = 10*ans+c-'0';
    }
    return ans;
}

vector<long long> numbersOnLine() {
    string s = readLine();
    vector<string> v(1);
    for (char c: s) {
        if (c == ' ') v.push_back("");
        else v.back().push_back(c);
    }
    vector<long long> ans;
    for (string& s: v) ans.push_back(toLong(s));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<bool> groups(6, true);
    vector<int> all;

    vector<long long> first = numbersOnLine();
    assert(first.size() == 2);
    all.push_back(first[0]);

    long long N = first[0];
    long long S = first[1];
    assert(N <= 2000000);
    assert(S <= 100000000000000ll);

    if (N > 2000) groups[3] = groups[4] = false;

    first = numbersOnLine();
    assert(first.size() == N);

    sort(first.begin(), first.end());

    assert((1 <= first[0]) && (first[0] <= 1000000000));
    for (int i = 1 ; i < N ; ++i) {

        assert((1 <= first[i]) && (first[i] <= 1000000000));
        if (first[i] > 10000) groups[3] = false;
        if (first[i] > 1000000) groups[2] = false;
        if (first[i] == first[i-1]) groups[1] = false;


    }


    for (int i = 1; i < groups.size(); i++) {
        if (groups[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}
