class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 1;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            int x = nums[i];
            int l = i + 1;
            int r = i + x;
            if(l < n)
                a[l] += 1;
            if(r + 1 < n)
                a[r + 1] -= 1;
        }
        for(int i = 1; i < n; i++)
            a[i] += a[i - 1];
        for(int i = 1; i < n; i++)
        {
            if(a[i] == 0)
                return 0;
        }
        return 1;
    }
};