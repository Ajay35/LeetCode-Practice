class Solution 
{
    public:
    int dp[32768],m,n;
    int dfs(int state)
    {
        if(state == 0) 
            return 0;
        if(dp[state] != INT_MAX) 
            return dp[state];
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(state & (1 << (i * n + j)))
                {
                    int t = state;
                    for(int k = 0; k < n; k++) 
                    {
                        t &= ~(1 << (i * n + k)); 
                    }
                    for(int k = 0; k < m; k++) 
                    {
                        t &= ~(1 << (k * n + j));
                    }
                    
                    dp[state] = min(dp[state], 1 + dfs(t));
                }
            }
        }
        return dp[state];
    }
    int removeOnes(vector<vector<int>>& grid) 
    {
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < 32768; i++) 
        {
            dp[i] = INT_MAX;
        }
        
        int state = 0;
        for(int i = 0;i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j]) state|=1<<(i*n+j);
            }
        }

        return dfs(state);
    }
};