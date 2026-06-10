class Solution {
public:
    bool isVowel(char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            int vowel = 0;
            int cons = 0;
            for (int j = i; j < n; j++) {
                if (isVowel(s[j])) {
                    vowel++;
                } else {
                    cons++;
                }
                if (vowel == cons && (vowel * cons) % k == 0) {
                    result++;
                }
            }
        }
        return result;
    }
};