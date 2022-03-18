class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int res = 0;
        int maxValue = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        sort(events.begin(), events.end());

        for (auto& e : events) {
            while (!pq.empty() && pq.top().first < e[0]) {
                maxValue = max(maxValue, pq.top().second);
                pq.pop();
            }
            res = max(res, maxValue + e[2]);
            pq.push({e[1], e[2]});
        }

        return res;
    }
};