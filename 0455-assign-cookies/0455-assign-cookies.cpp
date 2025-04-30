#include <algorithm>
#include <vector>

class Solution {
public:
    int findContentChildren(vector<int>& g,vector<int>& s) {
        int n = g.size(), m = s.size();
        int l = 0, r = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        while (l < m && r < n) { // Ensure r doesn't exceed g's size
            if (g[r] <= s[l]) {
                r++;
            }
            l++;
        }
        return r;
    }
};