class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq_map;
        int operations = 0;

        // Step 1: Count frequencies of each number
        for (int num : nums) {
            freq_map[num]++;
        }

        // Step 2: Calculate minimum operations
        for (auto& pair : freq_map) {
            int count = pair.second;

            // If any element appears only once, it is impossible to empty
            if (count == 1) {
                return -1;
            }

            // Formula handles remainders 0, 1, and 2 perfectly
            operations += (count + 2) / 3;
        }

        return operations;
    }
};
