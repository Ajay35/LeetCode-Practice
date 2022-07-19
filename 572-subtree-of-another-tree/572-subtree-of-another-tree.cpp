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
    
    bool checkIfSubtree(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr and root2 == nullptr) {
            return true;
        }
        
        if(root1 == nullptr or root2 == nullptr or root1->val != root2->val) {
            return false;
        }
        
        return checkIfSubtree(root1->left, root2->left) and checkIfSubtree(root1->right, root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) {
            return false;
        }
        bool ans = false;
        
        if(root->val == subRoot->val) {
            ans = checkIfSubtree(root, subRoot);
        }
        
        ans = ans or isSubtree(root->left, subRoot);
        ans = ans or isSubtree(root->right, subRoot);
        
        return ans;
    }
};