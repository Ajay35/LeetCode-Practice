class Solution {
public:
    vector<vector<int>> memo;
    int isValidPalindrome(string &s, int i, int j) {

        if (i == j)
            return 0;

        if (i == j - 1)
            return s[i] != s[j];

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s[i] == s[j])
            return memo[i][j] = isValidPalindrome(s, i + 1, j - 1);
        return memo[i][j] = 1 + min(isValidPalindrome(s, i + 1, j), isValidPalindrome(s, i, j - 1));
    }
    bool isValidPalindrome(string s, int k) 
    {
        memo.resize(s.length(), vector<int>(s.length(), -1));
        return isValidPalindrome(s, 0, s.length() - 1) <= k;
    }
};