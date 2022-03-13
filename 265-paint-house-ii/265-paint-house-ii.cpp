class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        
        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int>> dp(n, vector<int>(k));
        for(int i = 0; i < k; i++)
        {
            dp[0][i] = costs[0][i];
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < k; j++)
            {
                int choose = INT_MAX;
                for(int l = 0; l < k; l++)
                {
                    if(l != j)
                        choose=min(choose, dp[i - 1][l]);
                }
                dp[i][j] = costs[i][j] + choose;
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < k; i++)
        {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};