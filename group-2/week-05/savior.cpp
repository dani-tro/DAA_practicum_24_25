# include <bits/stdc++.h>
using namespace std;
double f(double x1, double y1, double x2, double y2, double x3, double v1, double v2)
{
    return sqrt((x3-x1)*(x3-x1)+y1*y1)/v1 + sqrt((x3-x2)*(x3-x2)+y2*y2)/v2; 
}
void solve()
{
    double x1,y1,x2,y2,v1,v2;
    cin >> x1 >> y1 >> x2 >> y2 >> v1 >> v2;
    double l, r, mid1, mid2;
    l = min(x1,x2);
    r = max(x1,x2);

    for(int i = 1; i <= 128; i++)
    {
        mid1 = l + (r-l)/3;
        mid2 = l + 2*(r-l)/3;
        double f1 = f(x1,y1,x2,y2,mid1,v1,v2);
        double f2 = f(x1,y1,x2,y2,mid2,v1,v2);
        if (f1 >= f2)
        {
            l = mid1;
        }
        if (f1 <= f2)
        {
            r = mid2;
        }
    }
    //cout << l << endl;
    cout << fixed << setprecision(5) << f(x1,y1,x2,y2,l,v1,v2) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}