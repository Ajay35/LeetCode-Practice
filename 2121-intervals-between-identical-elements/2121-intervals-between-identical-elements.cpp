class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        
        int n = arr.size();

        vector<vector<int>> a(100001);
        vector<vector<long long>> pre(100001);
        for (int i = 0; i < n; i++) {
            a[arr[i]].push_back(i);
        }
        
        vector<long long> ans(n);

        for(int i = 0; i <= 100000; i++)
        {
            for(int j = 0; j < a[i].size(); j++)
            {
                if(j > 0)
                    pre[i].push_back(a[i][j] + pre[i][j - 1]);
                else
                    pre[i].push_back(a[i][j]);
            }
        }
        for(int i = 0; i <= 100000; i++)
        {
            int len = pre[i].size();
            if(len == 1)
                continue;
            for(int j = 0; j < pre[i].size(); j++)
            {
                long long lsum;
                long long rsum;
                long long l_num = j;
                long long r_num = len - j - 1;
                if(l_num == 0)
                    lsum = 0;
                else
                    lsum = (l_num * a[i][j]) - pre[i][j - 1];
                
                if(r_num == 0)
                    rsum = 0;
                else
                    rsum = pre[i][len - 1] - pre[i][j];
                ans[a[i][j]] = lsum + (rsum - (r_num * a[i][j])); 
            }
        }
        return ans;
    }
};