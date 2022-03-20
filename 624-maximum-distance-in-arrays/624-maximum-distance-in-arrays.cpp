class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        vector<int> maximums(m);
        map<int, int> count;
        
        for(int i = 0; i < m; i++)
        {
            maximums[i] = arrays[i].back();
            count[arrays[i].back()]++;
        }
        sort(begin(maximums), end(maximums));
        int ans = 0;
        
        for(int i = 0; i < m; i++)
        {
            int ind = m - 1;
            while(ind >= 0)
            {
                if(maximums[ind] == arrays[i].back() and count[maximums[ind]] == 1)
                    ind--;
                else
                {
                    ans = max(ans, abs(arrays[i].front() - maximums[ind]));
                    break;
                }
            }
        }
        return ans;
    }
};