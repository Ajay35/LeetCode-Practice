class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(begin(pairs), end(pairs), [&](vector<int>& a, vector<int>& b){
           if(a[0] == b[0])
               return a[1] < b[1];
            return a[0] < b[0];
        });
            
        vector<int> dp(n, 1);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(pairs[j][1] < pairs[i][0] and dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};