class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int res = 0;
        int n = s.size();
        int dp[n + 1];
        memset(dp, 0 ,sizeof dp);
        
        for (int i = 1; i <= n; i++) {
		   // Need start from i - 1 to use values from last iteration
            for (int j = i - 1; j >= 1; j--) {
                if (s[i - 1] == s[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else {
                    dp[j] = 0;
                }
                
                res = max(res, dp[j]);
            }
        }
        
        return res;
    }
};