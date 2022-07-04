class Solution {
public:
    double dp[101][101];
    double f(int i, int k, int n, vector<double>& prefix) {
        if(k == 0) {
            double d = n - i;
            double sum = (prefix[n - 1] - (i > 0 ? prefix[i - 1]: 0))/d;
            return sum;
        }
        double& ans = dp[i][k];
        if(ans != -1) {
            return ans;
        }
        
        ans = 0;
        
        for(int j = i; j + k - 1 < n; j++) {        
            double sum = (prefix[j] - (i > 0 ? prefix[i - 1]: 0))/(double)(j - i + 1);
            ans = max(ans, sum + f(j + 1, k - 1, n, prefix));
        }
        
        return ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        
        if(nums.size() == 1) {
            return nums[0];
        }
        
        int n = nums.size();
        
        vector<double> numd(n);
        for(int i = 0; i < n; i++) {
            numd[i] = nums[i];
            if(i > 0) {
                numd[i] += numd[i - 1];
            }
        }
        for(int i = 0; i <= 100; i++) {
            for(int j = 0; j <= 100; j++) {
                dp[i][j] = -1.0;
            }
        }
        double ans = f(0 , k - 1, n, numd);
        return ans;
    }
};