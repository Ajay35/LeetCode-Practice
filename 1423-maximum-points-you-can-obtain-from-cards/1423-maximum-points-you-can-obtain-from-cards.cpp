class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        for(int i = 1; i < n; i++)
        {
            cardPoints[i] += cardPoints[i - 1];
        }
        long long ans = 0;
        for(int i = 0; i <= k; i++)
        {
            int le = i;
            int ri = n - (k - i);
            long long lsum = le > 0 ? cardPoints[le - 1]: 0;
            long long rsum = cardPoints[n-1] - (ri > 0 ? cardPoints[ri - 1]: 0);
            ans = max(ans, lsum + rsum);
        }
        return ans;
    }
};