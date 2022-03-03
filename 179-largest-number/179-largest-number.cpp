class Solution {
public:
    // check if num should be swappable.
    bool num(int x, int y) {
        string nx = to_string(x);
        string ny = to_string(y);
        if(nx + ny < ny + nx) {
            return 1;
        }
        return 0;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        string ans;
        for(int i = 0; i < n; i++) {
            int big = nums[i];
            int big_ind = -1;
            for(int j = i + 1; j < n; j++) {
                if(num(big, nums[j])) {
                    big = nums[j];
                    big_ind = j;
                }
            }
            if(big_ind != -1) {
                swap(nums[i], nums[big_ind]);
            }
            ans += to_string(nums[i]);
        }
        int ind = 0;
        while(ind + 1 < ans.size() and ans[ind] == '0')
            ind++;
        ans = ans.substr(ind);
        return ans;
    }
};