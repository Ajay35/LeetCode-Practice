class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        
        int n = arr.size();
        unordered_map<int, int>mp;
        
        for (int i = 0; i < n; i++)
        {
            mp[(k + arr[i] % k) % k]++;
        }
        
        for (int i = 0; i < n; i++) 
        {
            int r = (k + arr[i] % k) % k;
            if (r == 0) 
            {
                if (mp[r] % 2 != 0)
                    return false;
            } 
            else if (mp[r] != mp[k-r]) 
            {
                return false;
            }
        }
        
        return true;
    }
};