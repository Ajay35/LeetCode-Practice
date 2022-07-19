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
    int helper(TreeNode* root, int& ans) {
        if(root == nullptr) {
            return 0;
        }
        
        int le = 1 + helper(root->left, ans);
        int ri = 1 + helper(root->right, ans);
        
        ans = max(ans, le);
        ans = max(ans, ri);
        ans = max(ans, le + ri - 1);
        
        return max(le, ri);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans - 1;
    }
};