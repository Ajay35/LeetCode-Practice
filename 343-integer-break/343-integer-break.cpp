class Solution {
public:
    int integerBreak(int n) 
    {
        int dp[60] = {0};
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < i + (i != n); j++)
            {
                dp[i] = max(dp[i], dp[i - j] * j);
            }
        }
        return dp[n];    
    }
};