class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
            } else { // ch == ')'
                if (!st.empty() && st.top() == '(') {
                    st.pop(); // matched pair
                } else {
                    st.push(ch); // unmatched closing bracket
                }
            }
        }

        // Now the stack contains only unmatched brackets
        int open = 0, close = 0;
        while (!st.empty()) {
            if (st.top() == '(') open++;
            else close++;
            st.pop();
        }

        return open + close;
    }
};