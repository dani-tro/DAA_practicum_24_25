# include <bits/stdc++.h>
using namespace std;

int main()
{
    long long A,B,K,M,X,P;
    cin >> A >> K >> B >> M >> X;
    long long l = 1, r = 2*X/(A+B)+5, m;
    while(l < r)
    {
        m = (l+r)/2;
        long long total = (A+B)*m - (m/K)*A - (m/M)*B;
        //cout << l << " " << r << " " << m << " " << total << endl;
        if (total < X) l = m+1;
            else
                r = m;
    }
    cout << l << endl;
}