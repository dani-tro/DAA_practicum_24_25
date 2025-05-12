class Solution {
public:
    int dp[128][128];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int j = 0;
        while (j < n && !obstacleGrid[0][j]) {
            dp[0][j] = 1;
            j++;
        }
        while (j < n) {
            dp[0][j] = 0;
            j++;
        }

        int i = 0;
        while (i < m && !obstacleGrid[i][0]) {
            dp[i][0] = 1;
            i++;
        }
        while (i < m) {
            dp[i][0] = 0;
            i++;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};