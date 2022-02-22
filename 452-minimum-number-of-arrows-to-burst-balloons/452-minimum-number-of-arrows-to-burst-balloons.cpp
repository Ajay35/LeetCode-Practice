class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points),[&](vector<int>& a, vector<int>& b){
               return a[1] < b[1];
        });
        int first_end = points[0][1];
        int ans = 1;
        for(int i = 1; i < n; i++)
        {
            if(points[i][0] > first_end)
            {
                first_end = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};