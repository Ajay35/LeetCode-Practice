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
    long long helper(TreeNode* node, int& sum)
    {
        if(node == nullptr)
            return 0;
        long long lsum = helper(node->left, sum);
        long long rsum = helper(node->right, sum);
        if(lsum + rsum == node->val)
            sum++;
        return lsum + rsum + node->val;
        
    }
    int equalToDescendants(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};