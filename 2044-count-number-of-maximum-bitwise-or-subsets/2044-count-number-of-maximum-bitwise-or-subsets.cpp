class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        
        int biggest_or = 0;
        for(int i = 0; i < n; i++)
            biggest_or = biggest_or | nums[i];
        map<int, int> xors;
        int ans = 0;
        for(int i = 0; i < (1 << n); i++)
        {
            int t = 0;
            
            for(int j = 0; j < n; j++)
            {
                if(i & (1 << j))
                {
                    t = t | nums[j];
                }
            }
            if(biggest_or == t)
                ans++;
        }
        
        return ans;
    }
};