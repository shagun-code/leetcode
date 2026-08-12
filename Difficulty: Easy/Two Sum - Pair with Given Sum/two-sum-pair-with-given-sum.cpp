
#include <vector>
#include <unordered_map>

class Solution {
public:
    // 1. Changed return type to bool
    bool twoSum(std::vector<int>& arr, int target) { 
        std::unordered_map<int, int> hashmap;
        
        for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];
            
            if (hashmap.find(complement) != hashmap.end()) {
                // 2. This works perfectly now
                return true; 
            }
            
            hashmap[arr[i]] = i;
        }
        
        // 3. This works perfectly now
        return false; 
    }
};

