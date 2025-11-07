class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<pair<int, int>> adj[V];
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // because undirected
        }

        // Step 2: Define min-heap priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0}); // {weight, node}
        int sum = 0;

        // Step 3: Prim’s loop
        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;
            sum += wt;

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;
                if (!vis[adjNode]) {
                    pq.push({edw, adjNode});
                }
            }
        }

        return sum;
    }
};