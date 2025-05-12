class Solution {
public:
    int dp[128][128];
    int calc(int i, int j) {
        if (i == 1 || j == 1) return 1;
        
        if (dp[i][j]) return dp[i][j];

        return dp[i][j] = calc(i - 1, j) + calc(i, j - 1);
    }
    int uniquePaths(int m, int n) {
        return calc(n, m);
    }
};