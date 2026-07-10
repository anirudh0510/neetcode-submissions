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
    int solve(TreeNode* root, int count) {
        if (root == NULL)
            return count;

        int left = solve(root->left, count + 1);
        int right = solve(root->right, count + 1);

        return max(left, right);
    }

    int maxDepth(TreeNode* root) {
        return solve(root, 0);
    }
};