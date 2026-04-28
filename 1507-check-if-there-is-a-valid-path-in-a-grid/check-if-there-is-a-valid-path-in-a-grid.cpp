class Solution {
public:
    int m, n;
    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0,-1},{0,1}}},     // left, right
        {2, {{-1,0},{1,0}}},     // up, down
        {3, {{0,-1},{1,0}}},     // left, down
        {4, {{0,1},{1,0}}},      // right, down
        {5, {{0,-1},{-1,0}}},    // left, up
        {6, {{-1,0},{0,1}}}      // up, right
    };

    bool dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i == m - 1 && j == n - 1) return true;
        visited[i][j] = true;

        for (auto &dir : directions[grid[i][j]]) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !visited[new_i][new_j]) {
                // Check if the next cell has a direction back to current cell
                for (auto &back : directions[grid[new_i][new_j]]) {
                    if (new_i + back[0] == i && new_j + back[1] == j) {
                        if (dfs(grid, new_i, new_j, visited)) return true;
                    }
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(grid, 0, 0, visited);
    }
};
