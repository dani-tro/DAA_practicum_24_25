# include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int a[maxn];
void heapify(int curr)
{
    int par = curr/2;
    if (par == 0) return ;
    if (a[curr] > a[par]){
        swap (a[curr], a[par]);
        heapify(par);
    }
    return ;
}
void soak(int curr, int sz)
{
    int child = 2*curr;
    if (child > sz) return ;
    if (child + 1 <= sz && a[child+1] > a[child]) child = child + 1;
    // в child седи по-голямото дете
    if (a[curr] < a[child]){
        swap (a[curr], a[child]);
        soak(child, sz);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i++)
    {
        heapify(i);
    }
    for(int i = n; i > 0; i--)
    {
        swap(a[1], a[i]);
        soak(1, i-1);
    }
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}