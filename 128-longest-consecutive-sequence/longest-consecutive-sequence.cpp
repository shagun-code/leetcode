
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : numSet) {
            // Only start counting if 'num' is the START of a sequence
            if (!numSet.count(num - 1)) {
                int currEl = num;
                int count = 1;

                // Check for consecutive next elements
                while (numSet.count(currEl + 1)) {
                    currEl += 1;
                    count += 1;
                }

                maxLen = std::max(maxLen, count);
            }
        }

        return maxLen;
    }
};