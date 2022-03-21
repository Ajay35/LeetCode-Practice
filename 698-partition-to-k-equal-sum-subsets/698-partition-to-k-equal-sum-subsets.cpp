class Solution {
public:
    bool backtrack(vector<int>& arr, int index, int count, int currSum, int k, int targetSum, string& taken, unordered_map<string, bool>& memo) {
                       
        int n = arr.size();
      
        if (count == k - 1)
            return true;
        
        if (currSum > targetSum)
            return false;
        
        if (memo.find(taken) != memo.end()) 
            return memo[taken];
        
        if (currSum == targetSum)
            return memo[taken] = backtrack(arr, 0, count + 1, 0, k, targetSum, taken, memo);
        
        for (int j = index; j < n; ++j) 
        {
            if (taken[j] == '0') 
            {
                taken[j] = '1';
                if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken, memo))
                    return true;
                taken[j] = '0';
            }
        } 
        return memo[taken] = false;
    }
  
    bool canPartitionKSubsets(vector<int>& arr, int k) 
    {
        int totalArraySum = 0;
        int n = arr.size();
        unordered_map<string, bool> memo;
        
        for (int i = 0; i < n; ++i)
             totalArraySum += arr[i];
      
        if (totalArraySum % k != 0)
            return false;

        sort(arr.begin(), arr.end(), greater<int>());
      
        int targetSum = totalArraySum / k;
        string taken(n, '0');
      
        return backtrack(arr, 0, 0, 0, k, targetSum, taken, memo);
    }
};