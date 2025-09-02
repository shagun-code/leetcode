class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);  // Longest Prefix Suffix array
        int pre = 0, suff = 1;

        while (suff < n) {
            if (s[pre] == s[suff]) {
                pre++;
                lps[suff] = pre;
                suff++;
            } else {
                if (pre != 0) {
                    pre = lps[pre - 1];  // Try the previous longest prefix
                } else {
                    lps[suff] = 0;
                    suff++;
                }
            }
        }

        // The value at lps[n-1] gives the length of longest prefix which is also suffix
        return s.substr(0, lps[n - 1]);
    }
};