
class Solution(object):
    def minSubArrayLen(self, target, nums):
        n = len(nums)
        ans = float('inf')
        i = 0
        s = 0

        for j in range(n):
            s += nums[j]
            while s >= target:
                ans = min(ans, j - i + 1)
                s -= nums[i]
                i += 1

        return ans if ans != float('inf') else 0
