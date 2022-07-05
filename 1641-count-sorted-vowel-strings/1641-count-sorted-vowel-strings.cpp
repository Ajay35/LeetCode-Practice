class Solution {
public:
    string vowels= "aeiou";
    int dp[51][6];
    int f(int n, int ind) {
        if(n == 0) {
            return 1;
        }
        int& ans = dp[n][ind];
        if(ans != -1) {
            return ans;
        }
        ans = 0;
        for(int i = ind; i < vowels.size(); i++) {
            ans += f(n - 1, i);
        }
        return ans;
    }
    int countVowelStrings(int n) {
        memset(dp, -1, sizeof dp);
        int ans = f(n, 0);
        return ans;
    }
};