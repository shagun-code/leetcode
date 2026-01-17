#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());   // sort array
        int i = 0;
        int j = nums.size() - 1;
        int count = 0;

        while (i < j) {
            int sum = nums[i] + nums[j];  // compute pair sum

            if (sum < target) {
                // all pairs (i, i+1 ... j) are valid
                count += (j - i);
                i++;
            } else {
                j--;
            }
        }
        return count;
    }
};