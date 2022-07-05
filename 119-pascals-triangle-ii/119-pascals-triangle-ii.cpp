class Solution {
public:
    vector<int> getRow(int n) {
        if(n == 0) {
            return {1};
        }
        vector<vector<int>> dp(n + 1);
        
        dp[0].push_back(1);
        
        dp[1].push_back(1);
        dp[1].push_back(1);
        
        if(n <= 1) {
            return dp[n];
        }
        
        for(int i = 2; i <= n; i++) {
            dp[i].push_back(1);
            for(int j = 1; j < i; j++) {
                dp[i].push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
            }
            dp[i].push_back(1);
        }
        
        return dp[n];
        
    }
};