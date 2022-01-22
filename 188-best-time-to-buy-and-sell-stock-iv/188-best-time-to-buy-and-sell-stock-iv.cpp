class Solution {
public:
    int dp[1001][2][101];
    
    int f(vector<int>& prices, int day, int bought, int transactions)
    {
        if(day >= prices.size() or transactions == 0)
            return 0;
        
        int& ans = dp[day][bought][transactions];
        if(ans == -1)
            ans = 0;
        else
            return dp[day][bought][transactions];
        // if no share is bought then we can buy on this day.
        if(bought == 0)
        {
            // 1. buy.
            ans = max(ans, -prices[day] + f(prices, day + 1, 1 - bought, transactions));
        }
        else
        {
            // if some share is  bought then we can sell on this day.
            // 1. sell.
            ans = max(ans, prices[day] + f(prices, day + 1, 1 - bought, transactions - 1));
        }
        // dont do anything on this day.
        ans = max(ans, f(prices, day + 1, bought, transactions));
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        memset(dp, -1, sizeof dp);
        return f(prices, 0, 0, k);
    }
};