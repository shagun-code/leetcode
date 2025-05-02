#include <vector>
#include <algorithm>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); i += 3) {
            if (nums[i] != nums[i - 1]) return nums[i - 1];
        }
        return nums[nums.size() - 1];
    }
};