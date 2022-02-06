class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        int n = nums.size();
       vector<vector<int>> dp(n, vector<int>(3));
   
        dp[0][nums[0] % 3] = nums[0];
        for (int i = 1; i < n; i++) 
        {
            int num = nums[i];
            int mod = num % 3;
            if (mod == 0) {
                dp[i][0] = dp[i - 1][0] + num;
                dp[i][1] = dp[i - 1][1] > 0 ? dp[i - 1][1] + num : 0;
                dp[i][2] = dp[i - 1][2] > 0 ? dp[i - 1][2] + num : 0;
            } 
            else if (mod == 1) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] > 0 ? dp[i - 1][2] + num : 0);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + num);
                dp[i][2] = dp[i - 1][1] > 0 ? dp[i - 1][1] + num : 0;
            } 
            else 
            {    
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] > 0 ? dp[i - 1][1] + num : 0);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] > 0 ? dp[i - 1][2] + num : 0);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + num);
            }
        }

        return dp[n - 1][0];
    }
};