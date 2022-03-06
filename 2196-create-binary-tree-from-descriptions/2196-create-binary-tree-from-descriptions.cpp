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
    
    int g[100001][2];
    
    TreeNode* dfs(int u) {
        if(u == -1)
            return nullptr;
        TreeNode* node = new TreeNode;
        node->val = u;
        node->left = dfs(g[u][1]);
        node->right = dfs(g[u][0]);
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        int max_node = -1;
        memset(g, -1, sizeof g);
        map<int, int> inc;
        
        for(int i = 0; i < desc.size(); i++) {
            int p = desc[i][0];
            int c = desc[i][1];
            int l = desc[i][2];
            g[p][l] = c;
            inc[c]++;
        }
        TreeNode* root;
        for(int i = 0; i < desc.size(); i++) {
            if(inc[desc[i][0]] == 0) {
                root = dfs(desc[i][0]);
                break;
            }
            else if(inc[desc[i][1]] == 0) {
                root= dfs(desc[i][1]);
                break;
            }
        }
        return root;
    }
};