class Solution {
public:
    vector<long long> maximumEvenSplit(long long sum) 
    {
        vector<long long> res;
        for (int cur = 2; sum % 2 == 0 && sum > 0; cur += 2) 
        {
            if (sum - cur < cur + 2)
                res.push_back(sum);
            else
                res.push_back(cur);        
            sum -= res.back();
        }
        return res;
    }
};