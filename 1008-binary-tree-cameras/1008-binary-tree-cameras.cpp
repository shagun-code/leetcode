class Solution {
private:
    int ans = 0;

    int dfs(TreeNode* node) {
        if (node == nullptr) return 1;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if (left == -1 || right == -1) {
            ans++;
            return 0; // Place camera here
        }

        if (left == 0 || right == 0) {
            return 1; // Covered by child camera
        }

        return -1;
    }

public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == -1) {
            ans++; 
        }
        return ans;
    }
};