class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, INT_MAX);
        prev[0] = 0;

        for (int i = 0; i < n; i++) {
            vector<int> curr(amount + 1, INT_MAX);
            for (int target = 0; target <= amount; target++) {
                if (target >= coins[i] && curr[target - coins[i]] != INT_MAX)
                    curr[target] = min(curr[target], 1 + curr[target - coins[i]]);
                if (prev[target] != INT_MAX)
                    curr[target] = min(curr[target], prev[target]);
            }
            prev = curr;
        }

        return prev[amount] == INT_MAX ? -1 : prev[amount];
    }
};