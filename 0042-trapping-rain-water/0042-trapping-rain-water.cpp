class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> left(n), right(n);
        int maxL = 0, maxR = 0;

        for (int i = 0; i < n; ++i) {
            maxL = max(maxL, height[i]);
            left[i] = maxL;
        }

        for (int i = n - 1; i >= 0; --i) {
            maxR = max(maxR, height[i]);
            right[i] = maxR;
        }

        int water = 0;
        for (int i = 0; i < n; ++i) {
            water += min(left[i], right[i]) - height[i];
        }

        return water;
    }
};