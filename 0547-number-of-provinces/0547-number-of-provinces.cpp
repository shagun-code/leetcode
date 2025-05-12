class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1; // Mark as visited
        for (int i = 0; i < isConnected[node].size(); i++) {
            if (isConnected[node][i] == 1 && !vis[i]) { 
                dfs(i, isConnected, vis); 
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size(); // Get number of vertices
        vector<int> vis(v, 0); // Initialize visited array
        int cnt = 0;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) { // If not visited, start a DFS
                cnt++;
                dfs(i, isConnected, vis);
            }
        }
        return cnt;
    }
};