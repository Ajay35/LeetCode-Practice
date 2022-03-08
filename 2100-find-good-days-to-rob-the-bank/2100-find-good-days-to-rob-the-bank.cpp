class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        vector<int> le(n, 1);
        vector<int> ri(n, 1);
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] >= nums[i + 1])
                le[i] = le[i + 1] + 1; 
        }
        for(int i = 1; i < n; i++)
        {
            if(nums[i] >= nums[i - 1])
                ri[i] = ri[i - 1] + 1;
        }
        
        for(int i = k; i + k  < n; i++)
        {
            int dec = le[i - k] - le[i];
            int inc = ri[i + k] - ri[i];
            //cout<<i<<" "<<dec<<" "<<inc<<endl;
            if(dec >= k and inc >= k)
                ans.push_back(i);
        }
        return ans;
    }
};