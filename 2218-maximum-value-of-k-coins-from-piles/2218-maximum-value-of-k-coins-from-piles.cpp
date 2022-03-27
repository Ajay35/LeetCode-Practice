class Solution {
public:
    int dp[1001][2001] = {};
    int dfs(vector<vector<int>>& piles, int i, int k) 
    {
        if (i == piles.size() || k == 0)
            return 0;
        if (dp[i][k] == 0) 
        {
            int res = dfs(piles, i + 1, k),  sum = 0;
            for (int j = 0; j < piles[i].size() && k - j > 0; ++j) 
            {
                sum += piles[i][j];
                res = max(res, sum + dfs(piles, i + 1, k - j - 1));
            }   
            dp[i][k] = res;
        }
        return dp[i][k];
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        return dfs(piles, 0, k);
    }
};