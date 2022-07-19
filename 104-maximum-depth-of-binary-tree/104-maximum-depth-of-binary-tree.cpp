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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*, int>> que;
        que.push({root, 1});
        
        while(!que.empty()) {
            pair<TreeNode*, int> cur = que.front();
            que.pop();
            TreeNode* cur_node = cur.first;
            int ht = cur.second;
            if(cur_node->left == nullptr and cur_node->right == nullptr) {
                ans = max(ans, ht);
                continue;
            }
            
            if(cur_node->left) {
                que.push({cur_node->left, ht + 1});
            }
            
            if(cur_node->right) {
                que.push({cur_node->right, ht + 1});
            }
        }
        
        return ans;
    }
};