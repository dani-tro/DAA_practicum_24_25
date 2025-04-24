# include <bits/stdc++.h>
using namespace std;
const int maxN = 105;
bool vis[maxN][maxN];
int n, m;
bool valid(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= m && !vis[x][y];
}
int dx[4] = {-1, 1, 0, 0}, dy[4]={0,0,-1,1};
void dfs(int x, int y)
{
    vis[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx,ny))dfs(nx,ny);
    }
    // if(valid(x-1, y)) dfs(x-1, y);
    // if(valid(x+1, y)) dfs(x+1, y);
    // if(valid(x, y-1)) dfs(x, y-1);
    // if(valid(x, y+1)) dfs(x, y+1);
}
int main()
{
    cin >> n >> m;
    int k, x, y;
    cin >> k;
    for(int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        vis[x][y] = true;
    }
    int viruses = 0;
    for (int x = 1; x <= n; x ++)
        for(int y = 1; y <= m; y++)
        {
            if (!vis[x][y])
                {
                    viruses ++;
                    dfs(x, y);
                }
        }
    
        cout << viruses << endl;
}