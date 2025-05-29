#include <vector>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 1e9));

        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j]; // Base case: first row values
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                int leftDiagonal = (j > 0) ? matrix[i][j] + dp[i - 1][j - 1] : 1e9;
                int rightDiagonal = (j < m - 1) ? matrix[i][j] + dp[i - 1][j + 1] : 1e9;

                dp[i][j] = std::min({up, leftDiagonal, rightDiagonal});
            }
        }

        return *std::min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
