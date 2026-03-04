class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();    // Removed -1
        int n = mat[0].size(); // Removed -1
        
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        
        // Count 1s in each row and column
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        int count = 0;
        // Check if the current 1 is the only one in its row and column
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    if(row[i] == 1 && col[j] == 1) {
                        count++;
                    }
                }
            }
        }
        
        return count; // Fixed typo "counrt"
    }
};
