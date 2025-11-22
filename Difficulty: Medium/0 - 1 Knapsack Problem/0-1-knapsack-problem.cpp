#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knapsack(int maxWeight, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> dp(maxWeight + 1, 0);

        // Initialize with the first item
        for (int w = wt[0]; w <= maxWeight; w++) {
            dp[w] = val[0];
        }

        // Process remaining items
        for (int ind = 1; ind < n; ind++) {
            // Traverse backwards to avoid overwriting states we still need
            for (int w = maxWeight; w >= 0; w--) {
                int notTake = dp[w];
                int take = INT_MIN;
                if (wt[ind] <= w) {
                    take = val[ind] + dp[w - wt[ind]];
                }
                dp[w] = max(take, notTake);
            }
        }

        return dp[maxWeight];
    }
};