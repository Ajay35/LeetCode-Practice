class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        int m = requests.size();
        vector<int> ranges(n);
        
        for(int i = 0; i < m; i++)
        {
            int l = requests[i][0];
            int r = requests[i][1];
            
            ranges[l] += 1;
            
            if(r + 1 < n)
            {
                ranges[r + 1]--;
            }
        }
        sort(begin(nums), end(nums));
        
        long long mod = 1e9+7;
        for(int i = 1; i < n; i++)
        {
            ranges[i] += ranges[i - 1];
        }
        
        sort(begin(ranges), end(ranges));
        long long ans = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            ans += (nums[i] *(1ll)* ranges[i]);
            ans = ans % mod;
        }
        
        return ans;
    }
};