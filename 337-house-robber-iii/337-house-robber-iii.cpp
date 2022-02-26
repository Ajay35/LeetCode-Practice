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
    pair<int, int> dfs(TreeNode* root)
    {
        if(root == nullptr)
            return {0, 0};
        pair<int, int> le;
        pair<int, int> ri;
        le = dfs(root->left);
        ri = dfs(root->right);
        int rob = root->val + le.second + ri.second;
        int no_rob = max(le.first, le.second) + max(ri.first, ri.second);
        return {rob, no_rob};
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        return max(ans.first,ans.second);
    }
};