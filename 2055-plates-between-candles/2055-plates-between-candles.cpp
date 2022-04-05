class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) 
    {
        vector<int> c, res;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == '|')
                c.push_back(i);
        for (auto &q : queries) 
        {
            auto it_l = lower_bound(begin(c), end(c), q[0]);
            auto it_r = it_l == end(c) ? it_l : prev(upper_bound(it_l, end(c), q[1]));
            res.push_back(it_l < it_r ? *it_r - *it_l - (it_r - it_l) : 0);
        }
        return res;
    }
};