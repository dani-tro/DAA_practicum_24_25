class Solution {
public:
    int dp[128][128];
    int calc(int i, int j, const vector <vector <int> >& a) {
        if (i < 0 || j < 0) return 0;
        if (a[i][j]) return 0;

        if (dp[i][j]) return dp[i][j];

        return dp[i][j] = calc(i - 1, j, a) + calc(i, j - 1, a);
    }
    int uniquePaths(int m, int n) {
        return calc(n, m);
    }
};