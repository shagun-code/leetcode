class Solution {
public:
    bool check(int i,vector<int>& arr,vector<int>& vis){
        if(i<0||i>=arr.size()||vis[i]) return false;
        if(arr[i]==0)return true;
        vis[i]=1;
        return check(i+arr[i],arr,vis)||check(i-arr[i],arr,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),0);
        return check(start,arr,vis);
    }
};