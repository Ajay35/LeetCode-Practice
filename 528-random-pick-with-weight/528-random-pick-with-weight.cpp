class Solution {
    vector<int> prefixSums;

public:
    Solution(vector<int> &w) 
    {
        for (auto n : w)
            prefixSums.push_back(n + (prefixSums.empty() ? 
                0 : prefixSums.back()));
    }
    int pickIndex() 
    {
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSums.back();
        return upper_bound(begin(prefixSums), end(prefixSums), target) - begin(prefixSums);
    }
};