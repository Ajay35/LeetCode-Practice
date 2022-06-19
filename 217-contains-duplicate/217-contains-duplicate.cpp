class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int xor_num = 0;
        
        sort(begin(nums), end(nums));
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1])
                return true;
        }
        
        return false;
    }
};