class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, l = 0, r = 0, zeroes = 0;
        while (r < nums.size()) {  // ✅ should be <= nums.size()-1 or just r < nums.size()
            if (nums[r] == 0) zeroes++;

            while (zeroes > k) {   // ✅ use while here instead of if for proper adjustment
                if (nums[l] == 0) zeroes--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);  // ✅ calculate length directly without inner scope
            r++;
        }
        return maxLen;  // ✅ spelling correction from 'retrun' to 'return'
    }
};