
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int result = 0;
        
        // Loop over all lowercase English letters
        for (char letter = 'a'; letter <= 'z'; letter++) {
            int left_index = -1;
            int right_index = -1;
            
            // Find first and last occurrences of the character
            for (int i = 0; i < n; i++) {
                if (s[i] == letter) {
                    if (left_index == -1) {
                        left_index = i;
                    }
                    right_index = i;
                }
            }
            
            // If the character appears at least twice with characters in between
            if (left_index != -1 && right_index != -1 && right_index - left_index > 1) {
                unordered_set<char> st;
                for (int i = left_index + 1; i <= right_index - 1; i++) {
                    st.insert(s[i]);
                }
                result += st.size();
            }
        }
        
        return result;
    }
};