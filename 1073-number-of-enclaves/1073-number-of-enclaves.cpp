#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Mark boundary land cells as visited and enqueue them
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1; // Mark visited correctly
                    }
                }
            }
        }

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        // BFS traversal to mark reachable land cells from boundary
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + del_row[i];
                int ncol = col + del_col[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1; // Correct marking of visited cells
                }
            }
        }

        // Count enclaved land cells
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};