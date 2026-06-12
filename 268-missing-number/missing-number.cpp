class Solution { 
public: 
    int missingNumber(vector<int>& nums) { 
        int n = nums.size(); 
        
        // Loop from 0 to n (assuming LeetCode 268: Missing Number range [0, n])
        for (int i = 0; i <= n; i++) { 
            int flag = 0; 
            
            // Look through all elements of the array
            for (int j = 0; j < n; j++) { 
                if (nums[j] == i) { 
                    flag = 1; 
                    break; 
                } 
            } 
            
            // Check immediately after the inner loop finishes for this 'i'
            if (flag == 0) {
                return i; 
            }
        } 
        return -1; // Fallback return statement
    } 
};
