# include <bits/stdc++.h>
using namespace std;
long long n, m, q;
const long long maxn = 505;
long long dist[maxn][maxn];
void Floyd()
{
    for (long long k = 1; k <= n; k++)
    {
        for (long long i = 1; i <= n; i++)
            for (long long j = 1; j <= n; j++)
            {
                dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> q;
    long long i, j;
    long long a, b, c;
    for (i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            if (i != j)
                dist[i][j] = 1e13;
        }
    for(i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }
    Floyd();
    for (i = 1; i <= q; i++)
    {
        cin >> a >> b;
        if (dist[a][b] == 1e13) cout << -1 << endl;
        else
            cout << dist[a][b] << endl;
    }
}