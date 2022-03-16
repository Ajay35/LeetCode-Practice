class Solution {
public:
    int helper(string s, int k, int start,vector<int>& dp){
        if (start + k >= s.size())
            return 0;
        
        if(dp[start])
            return dp[start];
        
        int res = INT_MAX;
        for (int i = start; i - start <= k; ++i)
            if (s[i] == ' ')
                res = min(res, 
                          (k - (i-start)) * (k - (i-start)) + helper(s, k, i+1,dp)
                         );
        dp[start] = res;
        return res;
    }
    int minimumCost(string sentence, int k) {
        vector<int> dp(sentence.size(),0);
        return helper(sentence,k,0,dp);
    }
};