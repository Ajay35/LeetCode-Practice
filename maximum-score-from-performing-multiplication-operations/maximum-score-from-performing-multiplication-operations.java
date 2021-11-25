class Solution {
    private int[][] dp;
    private int[] nums, multipliers;
    private int n, m;
    
    private int dp(int i, int left) {
        if (i == m) {
            return 0; 
        }

        int right = n - 1 - (i - left);
            
        if (dp[i][left] == 0) {
            dp[i][left] = Math.max(multipliers[i] * nums[left] + dp(i + 1, left + 1), multipliers[i] * nums[right] + dp(i + 1, left));
        }

        return dp[i][left];
    }
    
    public int maximumScore(int[] nums, int[] multipliers) {
        n = nums.length;
        m = multipliers.length;
        this.nums = nums;
        this.multipliers = multipliers;
        this.dp = new int[m][m];
        return dp(0, 0);
    }
}