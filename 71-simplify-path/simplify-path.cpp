class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stringstream ss(path);
        stack<string> st; // Use stack<string> instead of stack<int>

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            if (token == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(token); // Push valid folder/file names
            }
        }

        if (st.empty()) {
            return "/";
        }

        string result = "";
        while (!st.empty()) {
            result = '/' + st.top() + result;
            st.pop(); // Crucial: pop the element to avoid an infinite loop!
        }

        return result;
    }
};
