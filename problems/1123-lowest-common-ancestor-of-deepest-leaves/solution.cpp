// Link: https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/
// Level: Medium
// Date: 2025-04-04

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
        pair<TreeNode*, int> f(TreeNode* root) {
            if (!root)
                return {nullptr, 0};
            auto [left, l] = f(root->left);
            auto [right, r] = f(root->right);
            if (l == r)
                return {root, l + 1};
            return l > r ? pair{left, l + 1} : pair{right, r + 1};
        }

        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return f(root).first;
        }
};