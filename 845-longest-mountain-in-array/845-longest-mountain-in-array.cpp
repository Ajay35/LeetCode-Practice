class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > nums[i - 1])
                dp[i][0] = dp[i - 1][0] + 1;
        }
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] > nums[i + 1])
                dp[i][1] = dp[i + 1][1] + 1;
        }
        int ans = 0;
        for(int i = 1; i + 1 < n; i++)
        {
            if(dp[i][0] > 1 and dp[i][1] > 1)
            {
                ans = max(ans, dp[i][0] + dp[i][1] - 1);
            }
        }
        return ans;
    }
};