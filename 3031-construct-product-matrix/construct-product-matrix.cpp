class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        static const int MOD = 12345; // Define the modulo constant
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));
        long long suffix = 1;

        // First pass: Calculate suffix products (from bottom-right to top-left)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = (int)suffix; // Store current suffix product at this position
                suffix = (suffix * grid[i][j]) % MOD; // Update suffix product
            }
        }

        long long prefix = 1;
        // Second pass: Multiply by prefix products (from top-left to bottom-right)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Multiply stored suffix product by current prefix product
                p[i][j] = (int)((p[i][j] * prefix) % MOD);
                prefix = (prefix * grid[i][j]) % MOD; // Update prefix product
            }
        }

        return p;
    }
};
