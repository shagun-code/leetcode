// User function Template for C++

class Solution {
  public:
    int f(int index, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
        // Base case: only one item to consider
        if (index == 0) {
            return (W / wt[0]) * val[0];
        }

        if (dp[index][W] != -1) return dp[index][W];

        // Option 1: Do not take the item
        int notTake = f(index - 1, W, val, wt, dp);

        // Option 2: Take the item (if it fits)
        int take = 0;
        if (wt[index] <= W) {
            take = val[index] + f(index, W - wt[index], val, wt, dp); // stay at same index
        }

        return dp[index][W] = max(take, notTake);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return f(n - 1, capacity, val, wt, dp);
    }
};