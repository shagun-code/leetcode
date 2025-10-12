class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long square = 1LL * mid * mid;  // prevent overflow
            if (square <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};