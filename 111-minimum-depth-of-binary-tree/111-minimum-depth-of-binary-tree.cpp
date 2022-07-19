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
    
    void helper(TreeNode* root, int level, int& ans) {
        if(root == nullptr) {
            return;
        }
        
        if(root->left == nullptr and root->right == nullptr) {
            ans = min(ans, level);
            return;
        }
        
        helper(root->left, level + 1, ans);
        helper(root->right, level + 1, ans);
    }
    int minDepth(TreeNode* root) {
        int ans = INT_MAX;
        
        if(root == nullptr) {
            return 0;
        }
        
        helper(root, 1, ans);
        return ans;
    }
};