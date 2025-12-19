class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits to integer
        long ans = 0;
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // 4. Handle overflow
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * ans);
    }
};