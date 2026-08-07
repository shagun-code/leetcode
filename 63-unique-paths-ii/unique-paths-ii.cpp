
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If starting cell or ending cell has an obstacle, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        // DP table using long long to prevent potential integer overflow during calculation
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        // Base case: Starting position
        dp[0][0] = 1;

        // Initialize first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) {
                dp[i][0] = 1;
            }
        }

        // Initialize first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1) {
                dp[0][j] = 1;
            }
        }

        // Fill DP table for the rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

