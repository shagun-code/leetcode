class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        q.push({start,0});  // {node, steps}
        
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        
        int mod = 100000;
        
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            for(auto it : arr){
                int num = (1LL * it * node) % mod;  // use long long to avoid overflow
                
                if(steps + 1 < dist[num]){
                    dist[num] = steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        
        return (dist[end] == 1e9) ? -1 : dist[end];
    }
};
