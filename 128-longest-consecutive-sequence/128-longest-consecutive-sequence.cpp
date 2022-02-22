class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        if(n == 0)
            return 0;
        int ans = 1, cur = 1;
        map<int, int> vis;
        for(int i = 0; i < n; i++)
        {
            vis[nums[i]] = 1 + vis[nums[i] - 1];
            ans = max(ans, vis[nums[i]]);
        }
        return ans;
    }
};