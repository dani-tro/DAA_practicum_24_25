#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N =2e5;

int n;
int a[N];

inline int sum(int i) { return a[i] + a[i + 1];}

int findResult()
{
    int start = 0, end = 3;
    int best = 0;
    for(; start < n - 1; ++start)
    {
         for(; end < n && a[end] <= sum(start); ++end);
         best = max(best, end - start);
    }
    return best;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >>n;
    for(int i = 0;i < n; ++i)
    {
        cin>>a[i];
    }

    sort(a, a + n);
    cout <<findResult() <<endl;
}
