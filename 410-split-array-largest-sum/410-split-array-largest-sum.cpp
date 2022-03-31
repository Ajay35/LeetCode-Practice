class Solution {
public:
    
    int memo[1001][51];
    
    int getMinimumLargestSplitSum(vector<int>& prefixSum, int currIndex, int subarrayCount) {
        int n = prefixSum.size() - 1;
        
        if (memo[currIndex][subarrayCount] != -1) {
            return memo[currIndex][subarrayCount];
        }
        
        if (subarrayCount == 1) {
            return memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
        }
        

        int minimumLargestSplitSum = INT_MAX;
        for (int i = currIndex; i <= n - subarrayCount; i++) 
        {
            int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];
            
            int largestSplitSum = max(firstSplitSum, 
                                      getMinimumLargestSplitSum(prefixSum, i + 1, subarrayCount - 1));
            
            minimumLargestSplitSum = min(minimumLargestSplitSum, largestSplitSum);
             
            if (firstSplitSum >= minimumLargestSplitSum) {
                break;
            }
        }
        
        return memo[currIndex][subarrayCount] = minimumLargestSplitSum;
    }
                       
    int splitArray(vector<int>& nums, int m) {
        memset(memo, -1, sizeof(memo));
        
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        return getMinimumLargestSplitSum(prefixSum, 0, m);
    }
};