/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // nodes[x][y] = multiset of values at column x and row y
        map<int, map<int, multiset<int>>> nodes;

        // BFS queue: each entry = (node, (x, y))
        queue<pair<TreeNode*, pair<int,int>>> todo;
        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int x = p.second.first;   // column index
            int y = p.second.second;  // row index

            nodes[x][y].insert(node->val);

            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        // Build the answer
        vector<vector<int>> ans;
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};