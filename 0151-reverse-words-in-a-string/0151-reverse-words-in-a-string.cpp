class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end()); // Reverse the entire string

        string ans = "";
        for (int i = 0; i < n; i++) {
            string word = "";
            // Skip spaces
            while (i < n && s[i] == ' ') i++;

            // Collect the word
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Reverse the word to restore its original order
            reverse(word.begin(), word.end());

            // Append to result if word is not empty
            if (!word.empty()) {
                ans += " " + word;
            }
        }

        // Remove leading space using substr(1)
        return ans.substr(1);
    }
};