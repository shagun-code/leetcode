class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;

        int original = x;
        long rev = 0;  // Use long to avoid overflow

        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }

        return rev == original;
    }
};