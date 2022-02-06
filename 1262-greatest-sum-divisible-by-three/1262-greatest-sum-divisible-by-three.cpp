class Solution {
public:
    int dp[40001][3];
    int f(int i, int s, vector<int>& nums)
    {
        if(i >= nums.size())
        {
            if(s == 0)
                return 0;
            return -1e9;            
        }
        
        int& ans = dp[i][s];
        if(dp[i][s] != -1)
            return ans;
        else
            ans = 0;
        ans = max(nums[i] + f(i + 1, (s + nums[i]) % 3, nums), f(i + 1, s, nums));
        return ans;
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        int ans = f(0, 0, nums);
        return ans;
    }
};