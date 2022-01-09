class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size(), res = n;
        int ones = count(begin(nums), end(nums), 1);
        
        for (int i = 0, j = 0, cnt = 0; i < n; ++i) 
        {
            while (j - i < ones)
                cnt += nums[j++ % n] == 1;
            res = min(res, ones - cnt);
            cnt -= nums[i] == 1;
        }
        return res;
            
    }
};