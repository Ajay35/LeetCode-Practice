class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long res = 0;
        vector<pair<int, int>> factors;
        for (int i = 1; i * i <= k; ++i)
            if (k % i == 0) {
                factors.push_back({i, 0});
                if (k / i != i)
                    factors.push_back({k / i, 0});
            }
        for (int n : nums) {
            long long gcd_nk = gcd(n, k);
            for (auto &[factor, cnt] : factors) {
                res += gcd_nk * factor % k ? 0 : cnt;
                if (gcd_nk == factor)
                    ++cnt;
            }
        }
        return res;
    }
};