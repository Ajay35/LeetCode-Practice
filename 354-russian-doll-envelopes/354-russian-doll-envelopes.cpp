class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int sz = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        vector<int> collector;
        for(auto& pair: envelopes)
        {
            auto iter = lower_bound(collector.begin(), collector.end(), pair[1]);
            if(iter == collector.end()) 
                collector.push_back(pair[1]);
            else if(*iter > pair[1]) *iter = pair[1];
        }
        return collector.size();
    }
};