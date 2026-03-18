class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> dp; 
        // dp[pos] = set of jump sizes that can reach this stone

        dp[0].insert(0); // frog starts at stone 0 with jump size 0

        for (int pos : stones) {
            for (int jump : dp[pos]) {
                for (int step = jump - 1; step <= jump + 1; step++) {
                    if (step > 0) {
                        int next = pos + step;
                        if (next == stones.back()) return true; // reached last stone
                        if (binary_search(stones.begin(), stones.end(), next)) {
                            dp[next].insert(step);
                        }
                    }
                }
            }
        }
        return false;
    }
};