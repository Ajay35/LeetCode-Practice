class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int xor_num = 0;
        
        map<int, int> store;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(store[nums[i]] == 1)
                return true;
            store[nums[i]] = 1;
        }
        
        return false;
    }
};