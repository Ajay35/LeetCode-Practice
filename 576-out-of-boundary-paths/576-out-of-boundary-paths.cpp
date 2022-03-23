class Solution {
public:
    long long dp[51][51][51];
    int mod = 1e9+7;
    
    long long findPath(int m, int n, int N, int i, int j)
    {
        if (i == m || j == n || i < 0 || j < 0) return 1;
        if (N == 0) 
            return 0;
        if(dp[N][i][j] != -1)
            return dp[N][i][j];
        long long& ans = dp[N][i][j];
        ans = 0;
        return ans = (findPath(m, n, N - 1, i - 1, j) % mod
            + findPath(m, n, N - 1, i + 1, j) % mod
            + findPath(m, n, N - 1, i, j - 1) % mod
            + findPath(m, n, N - 1, i, j + 1))%mod;
    }
    int findPaths(int m, int n, int N, int i, int j) {
        memset(dp,-1,sizeof dp);
        return findPath(m,n,N,i,j);
    }
};