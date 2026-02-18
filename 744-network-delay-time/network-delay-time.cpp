class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto i : times) {
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> dp(n+1, 1e9);
        queue<int> q;
        q.push(k);
        dp[k] = 0; dp[0] = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto i : adj[node]) {
                if(dp[i.first] > dp[node] + i.second) {
                    dp[i.first] = dp[node] + i.second;
                    q.push(i.first);
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end());
        if(ans == 1e9) ans = -1;
        return ans;
    }
};