

class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int maxi = INT_MIN;  // Initialize maxi to the smallest possible integer

        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] >= maxi) {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }

        reverse(ans.begin(), ans.end());  // To maintain the original order of leaders
        return ans;
    }
};