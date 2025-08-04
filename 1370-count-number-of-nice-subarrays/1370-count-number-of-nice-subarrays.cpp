class Solution {
public:
    // Helper function to count subarrays with at most 'goal' odd numbers
    int countSubarraysWithAtMostKOdd(vector<int>& nums, int goal) {
        if (goal < 0) return 0;  // No valid subarray can have negative odd count

        int l = 0, r = 0, ans = 0, oddCount = 0;
        int n = nums.size();

        while (r < n) {
            oddCount += (nums[r] % 2);  // Count odd numbers

            while (oddCount > goal) {
                oddCount -= (nums[l] % 2);
                l++;
            }

            ans += (r - l + 1);  // Add number of valid subarrays ending at r
            r++;
        }

        return ans;
    }

    // Main function: count subarrays with exactly 'goal' odd numbers
    int numberOfSubarrays(vector<int>& nums, int goal) {
        return countSubarraysWithAtMostKOdd(nums, goal) - countSubarraysWithAtMostKOdd(nums, goal - 1);
    }
};