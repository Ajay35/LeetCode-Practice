class Solution {
public:
    const int mod = 1e9+7;
    long long dp[10001][7][7];
    
    int gcd(int a , int b)
    {
       if(b==0) return a;
       a%=b;
       return gcd(b,a);
    }
    
    long long f(int n, int prev2, int prev1)
    {
        if(n == 0) {
            return 1;
        }
        
        long long& ans = dp[n][prev2][prev1] ;
        if(ans != -1) {
            return ans;
        }
        
        ans = 0;
        
        if(prev1 == 0 and prev2 == 0) {
            for(int i = 1; i <= 6; i++) {
                for(int j = 1; j <= 6; j++) {
                    if(i != j and gcd(i, j) == 1) {
                        ans += f(n - 2, i, j);
                        ans = ans % mod;
                    }
                }
            }
            return ans;
        }
        
        for(int i = 1; i <= 6; i++) {
            if(gcd(i, prev1) == 1 and i != prev1 and i != prev2) {
                ans += f(n - 1, prev1, i);
                ans %= mod;
            }
        }
        
        return ans % mod;
    }
    
    int distinctSequences(int n) {    
        if(n == 1) {
            return 6;
        }
        memset(dp, -1, sizeof dp);
        return f(n, 0, 0);
    }
};