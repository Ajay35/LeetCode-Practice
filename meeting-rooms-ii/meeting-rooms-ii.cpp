class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& interval) {
        int limit = 0;
        int n = interval.size();
        for(int i = 0; i < n; i++)
        {
            limit = max(limit, interval[i][1]);
        }
        vector<int> a(limit + 1);
        for(int i = 0; i < n; i++)
        {
            int l = interval[i][0];
            int r = interval[i][1];
            r--;
            a[l] += 1;
            if(r + 1 <= limit)
                a[r + 1] -= 1;
        }
        int ans = 1;
        for(int i = 1; i <= limit; i++)
        {
            a[i] += a[i - 1];
            ans = max(ans, a[i]);
        }
        return ans;
    }
};