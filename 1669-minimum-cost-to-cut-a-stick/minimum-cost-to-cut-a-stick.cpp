#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add boundaries (0 and n)
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();
        // dp[i][j] = minimum cost to cut stick between cuts[i] and cuts[j]
        vector<vector<int>> dp(c, vector<int>(c, 0));

        // Interval DP
        for (int len = 2; len < c; ++len) { // length of interval
            for (int i = 0; i + len < c; ++i) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]));
                }
            }
        }

        return dp[0][c - 1];
    }
};