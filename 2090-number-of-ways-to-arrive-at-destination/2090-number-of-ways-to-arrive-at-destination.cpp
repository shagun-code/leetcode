#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<pair<int, int>> adj[n];
        
        // Build the adjacency list
        for (auto& road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Min-heap priority queue for Dijkstra's algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto& [v, wt] : adj[u]) {
                long long newDist = d + wt;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                } else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};