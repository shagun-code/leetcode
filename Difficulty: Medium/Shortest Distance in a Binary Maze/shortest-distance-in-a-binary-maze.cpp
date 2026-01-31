#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int,int> source,
                     pair<int,int> destination) {
        int n = grid.size();
        int m = grid[0].size();

        // Check if source or destination is blocked
        if (grid[source.first][source.second] == 0 || 
            grid[destination.first][destination.second] == 0) {
            return -1;
        }

        // If source == destination
        if (source == destination) return 0;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[source.first][source.second] = 0;

        queue<pair<int,int>> q;
        q.push(source);

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i=0; i<4; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                    grid[newr][newc] == 1 && dist[r][c] + 1 < dist[newr][newc]) {
                    
                    dist[newr][newc] = dist[r][c] + 1;

                    if (make_pair(newr,newc) == destination) {
                        return dist[newr][newc];
                    }

                    q.push({newr,newc});
                }
            }
        }
        return -1; // No path found
    }
};
