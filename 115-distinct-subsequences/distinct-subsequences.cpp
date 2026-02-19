class Solution {
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        // Base Case: If t is exhausted, we found 1 subsequence
        if (j < 0) return 1;
        // Base Case: If s is exhausted but t is not, we found 0
        if (i < 0) return 0;
        
        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == t[j]) {
            // Option 1: Take s[i] + Option 2: Leave s[i]
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        } else {
            // Must leave s[i]
            return dp[i][j] = f(i - 1, j, s, t, dp);
        }
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // Initialize DP table with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }
};
