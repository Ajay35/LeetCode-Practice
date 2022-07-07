class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int missing_num = n;
        for(int i = 0; i < nums.size(); i++) {
            if(i != nums[i]) {
                missing_num = i;
                break;
            }
        }
        
        return missing_num;
    }
};