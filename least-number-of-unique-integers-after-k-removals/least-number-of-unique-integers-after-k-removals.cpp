class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        int n = arr.size();
        map<int, int> cnt;
        vector<int> f;
        for(int i = 0; i < n; i++)
        {
            cnt[arr[i]]++;
        }
        for(auto it: cnt)
        {
            f.push_back(it.second);
        }
        
        
        sort(f.begin(), f.end());
        int ind = 0;
        while(ind < f.size() and k >= f[ind])
        {
            k-=f[ind];
            ind++;
        }
        if(ind >= f.size())
            return 0;
        return f.size() - ind;
    }
};