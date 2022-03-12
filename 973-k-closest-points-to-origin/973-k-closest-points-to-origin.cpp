
class cmp {
public:
    bool operator()(pair<int, int> o1, pair<int, int> o2)
    {
        return (o1.second < o2.second);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        vector<vector<int>> ans(k, vector<int>(2));
        
        for(int i = 0; i < points.size(); i++)
        {
            int dd = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            if(pq.size() >= k)
            {
                if(pq.top().second > dd)
                {
                    pq.pop();
                    pq.push({i, dd});
                }
            }
            else
            {
                pq.push({i, dd});
            }
        }
        int ind = 0;
        while(!pq.empty())
        {
            ans[ind][0] = points[pq.top().first][0];
            ans[ind++][1] = points[pq.top().first][1];
            pq.pop();
        }
        return ans;
    }
};