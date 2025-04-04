/*
TASK: money
LANG: C++
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 200010;
int x[MAX];

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
      cin >> x[i];
    sort(x+1, x+n+1);
    int k, s, d, sum, m = 2;
    for(int i=1; i<=n-m; i++)
      { sum = x[i] + x[i+1];
        k = i + 1; s = n;
        while (k+1 < s)
          { d = (k+s)/2;
            if (sum > x[d]) k = d;
            else s = d;
          }
        if (sum > x[s]) k = s; 
        if (k != i+1 && m < k - i + 1)
          m = k - i + 1;
      }
    if (m == 2) cout << 1 << endl;
    else cout << m << endl;      
    return 0;
}  
