class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0;
        int preSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            preSum += arr[i];
            odd += preSum % 2;
        }

        return (int)(odd * (arr.size() + 1 - odd) % 1000000007);
    }
};