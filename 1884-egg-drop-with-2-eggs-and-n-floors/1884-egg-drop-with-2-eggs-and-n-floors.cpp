class Solution {
public:
    vector<vector<int>> dp;
    int eggDrop(int n, int k)
    {
        if (k == 1 || k == 0)
            return k;
        if (n == 1)
            return k;
        if(dp[n][k] != -1)
            return dp[n][k];
        int min = INT_MAX, x, res;
        for (x = 1; x <= k; x++) {
            res = max(eggDrop(n - 1, x - 1),eggDrop(n, k - x));
            if (res < min)
                min = res;
        }
        return dp[n][k] = min + 1;
    }
    int twoEggDrop(int n) {
        dp.resize(3, vector<int>(n + 1, -1));
        return eggDrop(2, n);
    }
};