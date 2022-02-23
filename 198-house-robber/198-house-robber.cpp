class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        vector<int> max_so_far(n);
        
        for(int i = 0; i < n; i++)
        {
            dp[i] = nums[i];
            
            if(i > 1)
            {
                dp[i] += max(max_so_far[i - 2], dp[i - 2]);
            }
            
            max_so_far[i] = dp[i];
            if(i > 0) max_so_far[i] = max(max_so_far[i], max_so_far[i - 1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};