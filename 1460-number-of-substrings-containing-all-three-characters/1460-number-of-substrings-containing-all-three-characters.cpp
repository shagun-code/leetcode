class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> lastSeen(3, -1);  // ✅ use vector for initialization
        int cnt = 0;
        for (int i = 0; i < n; i++) {  // ✅ loop till i < n, not n-1
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});  // ✅ use initializer list for min
            }
        }
        return cnt;  // ✅ spelling fix: retrun → return
    }
};