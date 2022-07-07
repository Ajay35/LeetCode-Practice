class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int, int> duplicate; 
        
        for(int num: nums) {
            if(duplicate.find(num) != duplicate.end()) {
                return true;
            }
            duplicate[num] = 1;
        }
        
        return false;
    }
};