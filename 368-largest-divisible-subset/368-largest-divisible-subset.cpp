class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> pre(n, -1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
        
        int mx = 0, mx_ind=-1;
        for(int i = 0; i < n; i++)
        {
            if(dp[i] > mx)
            {
                mx = dp[i];
                mx_ind = i;
            }
        }
        vector<int> ans;
        while(mx_ind != -1)
        {
            ans.push_back(nums[mx_ind]);
            mx_ind=pre[mx_ind];
        }
        return ans;
    }
};