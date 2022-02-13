class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(begin(beans), end(beans));
        vector<long long> prefix(n);
        prefix[0] = beans[0];
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1];
            prefix[i] += beans[i];
        }
        long long cur_sum = 0;
        long long ans = 1e16;
        for(int i = 0; i < n; i++)
        {
            long long cur = beans[i];
            long long sum = prefix[n - 1] - (i > 0 ? prefix[i - 1]: 0);
            sum -= (cur *(1ll)* (n - i));
            sum += cur_sum;
            ans = min(ans, sum);
            cur_sum += beans[i];
        }
        return ans;
    }
};