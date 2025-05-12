#include <vector>
#include <queue>

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, std::vector<std::vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        std::queue<std::pair<int, int>> q;
        q.push({row, col});

        // All possible 4-directional movements (up, down, left, right)
        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Traverse all possible neighbors
            for (int i = 0; i < 4; i++) {
                int neighbour_row = r + dRow[i];
                int neighbour_column = c + dCol[i];

                if (neighbour_row >= 0 && neighbour_row < n &&
                    neighbour_column >= 0 && neighbour_column < m &&
                    grid[neighbour_row][neighbour_column] == '1' &&
                    !vis[neighbour_row][neighbour_column]) {

                    vis[neighbour_row][neighbour_column] = 1;
                    q.push({neighbour_row, neighbour_column});
                }
            }
        }
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
        int cnt = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') { // New island found
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};