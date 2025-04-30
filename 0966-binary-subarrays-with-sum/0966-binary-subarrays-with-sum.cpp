class Solution {
public:
    int countSubarrays(vector<int>& nums, int goal) {
        if (goal < 0) return 0;  // Edge case handling

        int l = 0, r = 0, ans = 0, sum = 0;
        int n = nums.size();

        while (r < n) {
            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubarrays(nums, goal) - countSubarrays(nums, goal - 1);
    }
}; 

