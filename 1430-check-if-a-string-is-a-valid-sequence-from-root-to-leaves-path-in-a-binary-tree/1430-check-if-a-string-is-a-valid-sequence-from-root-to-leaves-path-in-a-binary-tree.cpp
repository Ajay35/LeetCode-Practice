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
    bool helper(TreeNode* root, int ind, vector<int>& arr) {
        if(root==nullptr or ind >= arr.size()){
            return false;
        }
        if(root->left == nullptr and root->right == nullptr and ind == arr.size() - 1) {
            return root->val == arr[ind];
        }
        bool ans = false;
        if(root->val == arr[ind]) {
            ans = ans or  helper(root->left, ind + 1, arr);
            ans = ans or helper(root->right, ind + 1, arr);
        }
        return ans;
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return helper(root, 0, arr);
    }
};