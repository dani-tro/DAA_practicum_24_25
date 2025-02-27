#include <bits/stdc++.h>

using namespace std;

#define MAX 1100

int n, a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];

    for(int i = 0; i < n - 1; i++)
    {
        int minn = a[i], minIndex = i;
        for(int j = i; j < n; j++)
        {
            if(a[j] < minn)
            {
                minn = a[j];
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
        for(int j = 0; j < n; j++)cout << a[j] << " ";
        cout << endl;
    }

    return 0;
}