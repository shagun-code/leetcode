class Solution {
public:
    vector<int> preOrder(Node* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* node = st.top();
            st.pop();

            result.push_back(node->data);  // use data + push_back

            // Push right first so left is processed first
            if (node->right != nullptr) {
                st.push(node->right);
            }
            if (node->left != nullptr) {
                st.push(node->left);
            }
        }

        return result;
    }
};