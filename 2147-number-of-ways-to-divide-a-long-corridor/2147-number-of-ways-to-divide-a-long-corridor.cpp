class Solution {
public:
    #define ll long long
  #define MOD 1000000007
  int dp[100005][3];
    
  ll help(int idx, string &s, int  cnt)
  {
    if(cnt > 2)
        return 0;
    if(idx == s.size())
      return cnt == 2;

    if(dp[idx][cnt] != -1)
      return dp[idx][cnt];
      
    ll ans = 0;
      
    if(s[idx] == 'P')
    {
      ans = (ans + help(idx + 1, s, cnt)) % MOD;
      if(cnt == 2) 
        ans = (ans + help(idx + 1, s, 0)) % MOD;
    }
    else
    {
      ans = (ans + help(idx +  1, s , cnt + 1) % MOD);
      if(cnt == 2)
      {    
        ans = (ans + help(idx + 1, s, 1)) % MOD;
      }
    }
    return dp[idx][cnt] = ans;
  }
    
    int numberOfWays(string s) {
        memset(dp,-1,sizeof(dp));  // initialise dp
        return help(0,s,0);
    }
};