  class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Base case: converting empty word1 to word2
        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i;  // converting word1[0...i-1] to empty word2

            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];  // no operation needed
                } else {
                    curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};

