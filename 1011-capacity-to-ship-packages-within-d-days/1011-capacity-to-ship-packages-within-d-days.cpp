class Solution {
public:
    bool check(int x, vector<int>& w, int d)
    {
        int cur_w = 0;
        int days = 0;
        for(int i = 0; i < w.size(); i++)
        {
            if(x < w[i])
                return false;
            if(cur_w + w[i] <= x)
            {
                cur_w += w[i];
            }
            else
            {
                cur_w = w[i];
                days++;
            }
        }
        days += (cur_w > 0);
        return days <= d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, r = 1e9;
        
        int ans = 1e9;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(check(mid, weights, days))
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};