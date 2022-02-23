class Solution {
public:
    int dp[59][59];
    int f(int n, int c)
    {
        if(n == 0)
        {
            return c > 1;
        }
        
        int& ans = dp[n][c];
        if(ans == -1)
            ans = 0;
        else
            return ans;
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans, i * f(n - i, c + 1));
        }
        return ans;
    }
    int integerBreak(int n) 
    {
        memset(dp, -1, sizeof dp);
        return f(n, 0);    
    }
};