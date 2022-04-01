class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        vector<int> firstHalf, secHalf;
        int n = nums.size() / 2;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i < n)firstHalf.push_back(nums[i]);
            else secHalf.push_back(nums[i]);
            sum += nums[i];
        }
        int l = sum / 2;

        vector<vector<int>> part1(n + 1, vector<int> ());
        vector<vector<int>> part2(n + 1, vector<int> ());

        for (int i = 0; i < (1 << n); i++) {
            int curSum = 0;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    curSum += firstHalf[j];
                    cnt++;
                }
            }
            part1[cnt].push_back(curSum);
        }
        for (int i = 0; i < (1 << n); i++) {
            int curSum = 0;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    curSum += secHalf[j];
                    cnt++;
                }
            }
            part2[cnt].push_back(curSum);
        }
        for (int i = 0; i <= n; i++)sort(part2[i].begin(), part2[i].end());
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {

            for (int j = 0; j < part1[i].size(); j++) {
                int cur = part1[i][j];
                int o = lower_bound(part2[n - i].begin(), part2[n - i].end(), l - cur) - part2[n - i].begin();
                if (o == part2[n - i].size())o--;

                ans = min(ans, abs((sum - (cur + part2[n - i][o]) ) - (cur + part2[n - i][o])));


            }
        }
        return ans;
    }
};