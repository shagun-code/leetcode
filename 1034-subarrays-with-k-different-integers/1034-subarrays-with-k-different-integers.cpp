#include <vector>
#include <unordered_map>

class Solution {
public:
    // Function to count subarrays with at most k distinct elements
    int countSubarraysWithAtMostKDistinct(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;
        int l = 0, r = 0, cnt = 0;

        while (r < nums.size()) {
            freqMap[nums[r]]++;  // Add the current element to frequency map

            while (freqMap.size() > k) {  // Shrink the window if distinct count exceeds k
                freqMap[nums[l]]--;
                if (freqMap[nums[l]] == 0) freqMap.erase(nums[l]);
                l++;  // Move left boundary forward
            }

            cnt += (r - l + 1);  // Count valid subarrays ending at r
            r++;  // Expand the right boundary
        }
        
        return cnt;
    }
    
    // Function to count subarrays where the number of distinct elements equals k
    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        return countSubarraysWithAtMostKDistinct(nums, k) - countSubarraysWithAtMostKDistinct(nums, k - 1);
    }
};