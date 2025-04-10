# include <bits/stdc++.h>
using namespace std;
const int maxn = 105, maxm = 105;
bool p[maxn][maxm];
bool vis[maxn][maxm];
int n, m;
bool isValid(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && !p[x][y];
}
int dx[4] = {-1,+1,0,0}, dy[4] = {0,0,-1,1};
void dfs(int x, int y)
{
    vis[x][y] = true;
    // if (isValid(x-1, y) && !vis[x-1][y])dfs(x-1, y);
    // if (isValid(x+1, y) && !vis[x+1][y])dfs(x+1, y);
    // if (isValid(x, y-1) && !vis[x][y-1])dfs(x, y-1);
    // if (isValid(x, y+1) && !vis[x][y+1])dfs(x, y+1);
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isValid(nx,ny) && !vis[nx][ny]) dfs(nx, ny);
    }
}
int main()
{
    cin >> n >> m;
    int k, i;
    cin >> k;
    int x, y;
    for(i = 1; i <= k; i++)
    {
        cin >> x >> y;
        p[x][y] = 1;
    }
    int viruses = 0;
    for (int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if (!vis[i][j] && !p[i][j])
            {
                viruses++;
                dfs(i, j);
            }
        }

    cout << viruses << endl;
}