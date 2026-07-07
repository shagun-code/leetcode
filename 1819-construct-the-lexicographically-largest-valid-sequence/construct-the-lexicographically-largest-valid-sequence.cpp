class Solution {
public:
    bool solve(int i, int n, vector<int>& result, vector<bool>& used) {
        // Base case: If we successfully filled the entire sequence
        if (i >= result.size()) {
            return true;
        }
        
        // FIX 1: Changed '=' to '!=' or check if it's already filled. 
        // If the current index 'i' is already filled by a previous number's second occurrence, 
        // we skip it and move to the next index.
        if (result[i] != -1) {
            return solve(i + 1, n, result, used);
        }
        
        // Try placing numbers from largest (n) to smallest (1) to get the lexicographically largest sequence
        for (int num = n; num >= 1; num--) {
            if (used[num]) {
                continue;
            }
            
            // Try placing 'num' at index 'i'
            used[num] = true;
            result[i] = num;
            
            if (num == 1) {
                // FIX 2: Added the missing 'n' parameter to the function call
                if (solve(i + 1, n, result, used) == true) {
                    return true;
                }
            } else {
                int j = i + num; // Distance condition: result[j] must be placed at i + num
                
                // FIX 3: Changed 'result[i] = -1' to 'result[j] == -1' 
                // We must check if the target index 'j' is valid and currently empty (-1)
                if (j < result.size() && result[j] == -1) {
                    result[j] = num;
                    
                    if (solve(i + 1, n, result, used) == true) {
                        return true;
                    }
                    
                    // Backtrack target index
                    result[j] = -1;
                }
            }
            
            // Undo placement if the path doesn't lead to a solution (Backtracking)
            used[num] = false;
            result[i] = -1;
        }
        
        // If no number can fit in position 'i', return false to trigger backtracking in the parent call
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, -1);
        vector<bool> used(n + 1, false);
        solve(0, n, result, used);
        return result;
    }
};