typedef long long ll;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int N = obstacleGrid.size();
        if (N == 0)
            return 0;
        int M = obstacleGrid[0].size();
        vector<vector<ll>> dp(N + 5, vector<ll>(M + 5, 0));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (obstacleGrid[i - 1][j - 1]) {
                    dp[i][j] = 0;
                } else if (i == 1 && j == 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[N][M];
    }
};