class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;
        int m = pushed.size();

        while (i < m) {
            st.push(pushed[i]);
            i++;

            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};