class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for(int i = 0; i < n; i++)
        {
            if(coins[i] <= amount)
                dp[coins[i]] = 1;
        }
        for(int i = 2 ; i <= amount; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i - coins[j] >= 0 and dp[i] > dp[i - coins[j]] + 1)
                {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
        if(dp[amount] == 1e9)
            return -1;
        return dp[amount];
    }
};