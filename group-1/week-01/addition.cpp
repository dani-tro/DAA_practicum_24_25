#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    long long sum = 0;

    long long currNum;
    for (int i = 0; i < n; i++) 
    {
        cin >> currNum;
        sum += currNum;
    }

    cout << sum << endl;
}