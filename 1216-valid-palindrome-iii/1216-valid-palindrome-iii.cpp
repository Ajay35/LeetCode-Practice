class Solution {
public:
    bool isValidPalindrome(string s, int k) 
    {
        vector<vector<int>> memo(s.length(), vector<int>(s.length(), 0));
        for (int i = s.length() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < s.length(); j++) 
            {
                if (s[i] == s[j])
                    memo[i][j] = memo[i + 1][j - 1];
                else
                    memo[i][j] = 1 + min(memo[i + 1][j], memo[i][j - 1]);
            }
        }
        return memo[0][s.length() - 1] <= k;
    }
};