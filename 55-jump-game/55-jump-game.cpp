class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 1;
        int mx = 0;
        for(int i = 0; i < n; i++)
        {
            if(i <= mx)
            {
                nums[i] = i + nums[i];
                mx = max(mx, nums[i]);
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};