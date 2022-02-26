class Solution {
public:
    long long dp[100001][2];
    long long f(vector<int>& nums, int ind, int bit)
    {
        if(ind >= nums.size())
            return 0;
        //take the current num with given parity.
        if(dp[ind][bit] != -1)
            return dp[ind][bit];
        long long ans1 = (bit == 0? (long long) nums[ind]:(long long) (-nums[ind])) + f(nums, ind + 1, 1 - bit);
        // leave the number..
        long long ans2 = f(nums, ind + 1, bit); 
        return dp[ind][bit] = max(ans1, ans2);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return f(nums, 0, 0);   
    }
};