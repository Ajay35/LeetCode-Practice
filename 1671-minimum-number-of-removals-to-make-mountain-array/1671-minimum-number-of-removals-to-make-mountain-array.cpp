class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> le(n, 1);
        vector<int> ri(n, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i] and le[i] < le[j] + 1)
                {
                    le[i] = le[j] + 1;
                }
            }
        }
        
        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = n - 1; j > i; j--)
            {
                if(nums[i] > nums[j] and ri[i] < ri[j] + 1)
                {
                    ri[i] = ri[j] + 1;
                }
            }
        }
        int ans = n;
        for(int i = 1; i+1 < n; i++)
        {
            int len = le[i] + ri[i] - 1;
            if(le[i] > 1 and ri[i] > 1)
            {
                //cout<<i<<" "<<le[i]<<" "<<ri[i]<<endl;
                ans = min(ans, n - len);
            }
        }
        return ans;
    }
};