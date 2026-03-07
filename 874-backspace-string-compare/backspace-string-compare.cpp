class Solution {
public:
    // Helper function to process the string
    string remove_characters(const string &str) {
        stack<char> st;
        for(char c : str) {
            if(c == '#' && !st.empty()) {
                st.pop();
            } else if(c != '#') {
                st.push(c);
            }
        }
        // Convert stack to string in correct order
        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool backspaceCompare(string s, string t) {
        return remove_characters(s) == remove_characters(t);
    }
};