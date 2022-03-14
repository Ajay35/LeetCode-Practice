class Solution {
public:
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e9);
        dp[0] = 0;
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j <= min(n - 1, i + nums[i]); j++)
            {
                dp[j] = min(dp[j], 1 + dp[i]);
            }
        }
        return dp[n - 1];
    }
};