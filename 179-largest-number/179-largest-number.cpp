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
        sort(begin(nums), end(nums),[](int x, int y) {
            string nx = to_string(x);
            string ny = to_string(y);
            if(nx + ny > ny + nx) {
                return 1;
            }
            return 0;
        });
        for(int i = 0; i < n; i++)
        {
            ans += to_string(nums[i]);
        }
        int ind = 0;
        while(ind + 1 < ans.size() and ans[ind] == '0')
            ind++;
        ans = ans.substr(ind);
        return ans;
    }
};