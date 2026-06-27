class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        
        unordered_map<int, int> ballToColor;  // Tracks the current color of each ball
        unordered_map<int, int> colorCount;   // Tracks the frequency of each color
        
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];
            
            // If the ball was already colored before
            if (ballToColor.count(ball)) {
                int prevColor = ballToColor[ball];
                colorCount[prevColor]--;
                
                // If no other balls have this old color, remove it from the map
                if (colorCount[prevColor] == 0) {
                    colorCount.erase(prevColor);
                }
            }
            
            // Assign the new color to the ball
            ballToColor[ball] = color;
            colorCount[color]++;
            
            // The number of distinct colors is simply the size of our colorCount map
            result[i] = colorCount.size();
        }
        
        return result;
    }
};