class Solution {
public:
    int dp[5000][6][16];
    const int M = 1000000007;
    
    int dieSimulator(int n, vector<int>& rollMax) {
        return dfs(n, rollMax, -1, 0);
    }
    
     int dfs(int dieLeft, vector<int>& rollMax, int last, int curlen)
     {
        if(dieLeft == 0) 
            return 1;
        if(last >= 0 && dp[dieLeft][last][curlen] > 0) 
            return dp[dieLeft][last][curlen];
        int ans = 0;
        for(int i=0; i<6; i++)
        {
            if(i == last && curlen == rollMax[i]) 
                continue;
            ans = (ans + dfs(dieLeft - 1, rollMax, i, i == last ? curlen + 1 : 1)) % M;
        }
        if(last >= 0) 
            dp[dieLeft][last][curlen] = ans;
        return ans;
    }
};