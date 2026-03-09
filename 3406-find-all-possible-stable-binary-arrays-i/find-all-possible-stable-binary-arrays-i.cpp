class Solution {
public:
    int M = 1e9 + 7;
    // Memoization table: dp[onesLeft][zerosLeft][lastWasOne]
    vector<vector<vector<int>>> dp;

    int solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit) {
        if (onesLeft == 0 && zerosLeft == 0) return 1;

        if (dp[onesLeft][zerosLeft][lastWasOne] != -1)
            return dp[onesLeft][zerosLeft][lastWasOne];

        long long result = 0;

        if (lastWasOne) { 
            // explore zeros
            for (int len = 1; len <= min(zerosLeft, limit); len++) {
                result = (result + solve(onesLeft, zerosLeft - len, false, limit)) % M;
            }
        } else { 
            // explore ones
            for (int len = 1; len <= min(onesLeft, limit); len++) {
                result = (result + solve(onesLeft - len, zerosLeft, true, limit)) % M;
            }
        }

        return dp[onesLeft][zerosLeft][lastWasOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        dp.assign(one + 1, vector<vector<int>>(zero + 1, vector<int>(2, -1)));

        int startWithOne = solve(one, zero, false, limit);
        int startWithZero = solve(one, zero, true, limit);

        return (startWithOne + startWithZero) % M;
    }
};