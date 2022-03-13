class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(20001);
        for(int i = 0; i < nums.size(); i++)
        {
            sum[nums[i]] += nums[i];
        }
        
        vector<int> dp(20001);
        for(int i = 1; i <= 20000; i++)
            dp[i] = sum[i];
        for(int i = 2; i <= 20000; i++)
        {
            dp[i] = max(dp[i - 1], dp[i] + dp[i - 2]);
        }
        return dp[20000];
    }
};