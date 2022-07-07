class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> store;
        int n = nums.size();
        
        for(int i = 0; i < nums.size(); i++) {
            store[nums[i]]++;
        }
        
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            if(store.find(i) == store.end()) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};