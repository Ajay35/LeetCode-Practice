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
    void f(TreeNode* node, int num, int& sum)
    {
        if(node == nullptr)
        {
            return;
        }
        if(node->left ==nullptr and node->right == nullptr)
        {
            sum += num * 10 + node->val;
            return;
        }
        f(node->left, num * 10 + node->val, sum);
        f(node->right, num * 10 + node->val, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        f(root, 0, sum);
        return sum;
    }
};