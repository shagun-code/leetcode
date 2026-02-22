#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int f(int i, int j, string &p, string &s, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return 1;
        if (i < 0 && j >= 0) return 0;
        if (j < 0 && i >= 0) {
            for (int ii = 0; ii <= i; ii++) {
                if (p[ii] != '*') return 0;
            }
            return 1;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = f(i - 1, j - 1, p, s, dp);
        }
        if (p[i] == '*') {
            return dp[i][j] = f(i - 1, j, p, s, dp) || f(i, j - 1, p, s, dp);
        }
        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, p, s, dp);
    }
};
