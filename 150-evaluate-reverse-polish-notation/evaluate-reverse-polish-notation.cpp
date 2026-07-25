class Solution {
private:
    int operate(int a, int b, const string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;
        return 0;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string &token : tokens) {
            // Use double quotes for string comparisons
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int result = operate(a, b, token);
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};