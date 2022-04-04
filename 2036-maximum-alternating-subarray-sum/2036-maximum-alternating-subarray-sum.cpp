class Solution {
public:
long long maximumAlternatingSubarraySum(vector<int>& nums)
{
	int n = nums.size();
	long long add = 0, sub = 0, preAdd = nums[0], preSub = 0;
	long long res = nums[0];

	for (int i = 1; i < n; i++)
	{
		sub = preAdd - nums[i];
		add = max<long long int>(preSub + nums[i], nums[i]);
		preSub = sub;
		preAdd = add;

		res = max({res, add, sub});
	}

	return res;
    }
};