class Solution {
public:
    int kthMissing(vector<int>& arr, int k) {
        unordered_set<int> s(arr.begin(), arr.end());
        int current = 1;
        
        while (k > 0) {
            if (s.find(current) == s.end()) {
                k--; // Found a missing number
                if (k == 0) {
                    return current;
                }
            }
            current++;
        }
        return current;
    }
};
