#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Optimized integer-based mapping to prevent string conversion overhead and overflow crashes
    int getMappedNum(int num, const vector<int>& mapping) {
        if (num == 0) return mapping[0];
        
        long long mappedNum = 0;
        long long placeValue = 1;
        int temp = num;
        
        while (temp > 0) {
            int digit = temp % 10;
            mappedNum += (long long)mapping[digit] * placeValue;
            placeValue *= 10;
            temp /= 10;
        }
        return mappedNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        // Stores {MappedValue, OriginalIndex}
        vector<pair<int, int>> vec;
        vec.reserve(n);
        
        for (int i = 0; i < n; i++) {
            int mappedValue = getMappedNum(nums[i], mapping);
            vec.push_back({mappedValue, i});
        }
        
        // Sorts by mapped value. Ties are broken by the original index (i)
        sort(vec.begin(), vec.end());
        
        vector<int> result;
        result.reserve(n);
        for (const auto &p : vec) {
            result.push_back(nums[p.second]);
        }
        
        // CRITICAL FIX: Added missing return statement
        return result;
    }
};
