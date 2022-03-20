/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> parent;
    map<TreeNode*, bool> vis;
    void get_parent(TreeNode* cur, TreeNode* p)
    {
        if(cur == nullptr)
            return;
        parent[cur] = p;
        get_parent(cur->left, cur);
        get_parent(cur->right, cur);
    }
    void dfs(TreeNode* u, int k, vector<int>& ans)
    {
        if(u == nullptr)
            return;
        if(vis.find(u) != vis.end())
            return;
        vis[u] = true;
        if(k == 0)
        {
            ans.push_back(u->val);
            return;
        }
        dfs(u->left, k - 1, ans);
        dfs(u->right, k - 1, ans);
        dfs(parent[u], k - 1, ans);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        get_parent(root, nullptr);
        vector<int> ans;
        dfs(target, k, ans);
        return ans;
    }
};