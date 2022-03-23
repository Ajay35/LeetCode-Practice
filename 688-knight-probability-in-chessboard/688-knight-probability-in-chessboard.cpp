class Solution {
public:
    
    int dx[8] = {2,-2,2,-2,1,-1,1,-1};
    int dy[8] = {1,1,-1,-1,2,2,-2,-2};
    
    double dp[101][26][26] ={0.0};
    
    double f(int n, int k, int r, int c)
    {
        if(r >= n or r < 0 or c >= n or c < 0)
            return 0;
        if(k == 0)
            return 1.0;
        
        if(dp[k][r][c] != 0.0)
        {
            return dp[k][r][c];
        }
        
        double ans = 0;
        
        for(int i = 0; i < 8; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
            ans += 0.125 * f(n, k - 1, nr, nc);
        }
        return dp[k][r][c] = ans;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        
        return f(n, k, row, column);
    }
};