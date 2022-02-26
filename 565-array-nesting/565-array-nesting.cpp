class Solution {
public:
    int dfs(int num, vector<int>& a, vector<bool>& vis)
    {
        if(vis[num])
            return 0;
        vis[num] = true;
        return 1 + dfs(a[num], a, vis);
    }
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis;
        int ans = 0;
        vis.resize(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                ans = max(ans, dfs(nums[i], nums, vis));
            }
        }
        return ans;
    }
};