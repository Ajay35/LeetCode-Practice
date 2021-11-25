class Solution {
    int[] dp;
    
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        dp = new int[n + 2];
        
        Arrays.fill(dp, 0 , n + 2, 1000000000);
        dp[0] = dp[1] = 0;
        
        for(int i = 2; i < n + 2; i++)
        {
            if(i - 1 < n) 
                dp[i] = cost[i - 1] + dp[i - 1];
            
            dp[i] = Math.min(dp[i], cost[i - 2] + dp[i - 2]);
            
        }
        return Math.min(dp[n], dp[n + 1]);
    }
}