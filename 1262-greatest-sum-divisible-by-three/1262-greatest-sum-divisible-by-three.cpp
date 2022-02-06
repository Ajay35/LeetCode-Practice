class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        return maxSumDivK(nums, 3);
    }
    
    int maxSumDivK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(k, INT_MIN);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1], mod = nums[i - 1] % k;
            vector<int> newDp(k);
            
            for (int j = 0; j < k; j++) {
                newDp[j] = max(dp[j], dp[(j + mod) % k] + num);
            }
            
            dp = newDp;
        }
        
        return dp[0];
    }
};