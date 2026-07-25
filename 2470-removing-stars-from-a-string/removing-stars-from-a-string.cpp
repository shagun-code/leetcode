class Solution {
public:
    string removeStars(string s) {
        int n = s.size();          // Fixed: specified 's.size()'
        stack<char> st;            // Fixed: stack holds 'char', not 'int'

        for (int i = 0; i < n; i++) {
            if (!st.empty() && s[i] == '*') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }   

        string temp = "";          // Fixed: declared 'temp' outside the loop as string
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();              // Fixed: pop the element to avoid infinite loop
        }

        reverse(temp.begin(), temp.end());

        return temp; 
    }
};