class Solution {
public:
    // Helper function to check if substring s[l..r] is palindrome
    bool ispal(string &s, int l, int r, vector<vector<int>> &dp) {
        if (l >= r) return true;
        if (dp[l][r] != -1) return dp[l][r];
        if (s[l] != s[r]) return dp[l][r] = false;
        return dp[l][r] = ispal(s, l + 1, r - 1, dp);
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> path;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        function<void(int)> backtrack = [&](int start) {
            // base case 
            if (start == n) {
                res.push_back(path);
                return;
            }
            for (int end = start; end < n; end++) {
                if (ispal(s, start, end, dp)) {
                    path.push_back(s.substr(start, end - start + 1));
                    backtrack(end + 1);
                    path.pop_back();
                }
            }
        };

        backtrack(0);
        return res;
    }
};