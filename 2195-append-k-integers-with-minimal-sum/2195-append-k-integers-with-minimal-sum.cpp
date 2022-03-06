class Solution {
public:
    long long totalSum(long long n) {
        return (n*(n + 1))/ 2;
    }
    long long get_sum(long long l, long long r) {
        return totalSum(r) - totalSum(l - 1);
    }
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum = 0;
        sort(begin(nums), end(nums));
        int n = nums.size();
        for(int i = 0; i < n and k > 0; i++) {
            long long l = (i == 0 ? 1: nums[i - 1] + 1);
            long long r = nums[i] - 1;
            if(l <= r) {
                if(r - l + 1 > k) {
                    r = l + k - 1;
                    //cout<<"if:"<<l<<" "<<r<<endl;
                    k = 0;
                }
                else {
                    //cout<<"else:"<<l<<" "<<r<<endl;
                    k -= (r - l + 1);
                }
                sum += get_sum(l, r);
            }
        }
        if(k > 0) {
            sum += get_sum(nums[n - 1] + 1, nums[n - 1] + k);
        }
        return sum;
    }
};