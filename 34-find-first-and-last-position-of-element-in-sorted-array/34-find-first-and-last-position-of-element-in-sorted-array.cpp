class Solution {
public:
    int bs_upper_bound(vector<int>& a, int n, int x) {
        int l = 0;
        int h = n; // Not n - 1
        while (l < h) 
        {
            int mid =  l + (h - l) / 2;
            if (x >= a[mid]) 
            {
                l = mid + 1;
            } 
            else 
            {
                h = mid;
            }
        }
        return l;
    }

    int bs_lower_bound(vector<int>& a, int n, int x) 
    {
        int l = 0;
        int h = n; 
        while (l < h) 
        {
            int mid =  l + (h - l) / 2;
            if (x <= a[mid]) 
            {
                h = mid;
            } else 
            {
                l = mid + 1;
            }
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = bs_lower_bound(nums, n, target);
        vector<int> res(2);
        res[0] = -1;
        res[1] = -1;
        if(!binary_search(begin(nums), end(nums), target))
        {
            return res;       
        }
        int end = bs_upper_bound(nums, n, target);
        
        res[0] = start;
        res[1] = end-1;
        
        return res;
    }
};