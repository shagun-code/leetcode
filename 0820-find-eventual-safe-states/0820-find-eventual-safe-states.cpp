class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();  // Number of nodes
        vector<vector<int>> adjRev(V);  // Reversed graph
        vector<int> indegree(V, 0);     // Indegree of reversed graph

        // Build the reversed graph and compute indegrees
        for (int u = 0; u < V; ++u) {
            for (int v : graph[u]) {
                adjRev[v].push_back(u);
                indegree[u]++;
            }
        }

        // Queue for nodes with 0 indegree (terminal nodes)
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform BFS to find safe nodes
        vector<bool> safe(V, false);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int neighbor : adjRev[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Collect all safe nodes
        vector<int> safeNodes;
        for (int i = 0; i < V; ++i) {
            if (safe[i]) {
                safeNodes.push_back(i);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());  // Optional: return in sorted order
        return safeNodes;
    }
};