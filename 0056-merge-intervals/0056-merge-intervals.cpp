#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // Sort by starting times
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            // If ans is empty or there's no overlap
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]); // <- fixed the incorrect index from intervals[1]
            } else {
                // Overlapping intervals, merge them
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};