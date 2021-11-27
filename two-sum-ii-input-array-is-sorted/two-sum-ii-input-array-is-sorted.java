class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int l = 0, r = n - 1;
        int[] ans = new int[2];
        while(l < n)
        {
            int le = nums[l];
            int ri = nums[r];
            if(le + ri == target)
            {
                ans[0] = l + 1;
                ans[1] = r + 1;
                break;
            }
            else if(le + ri < target)
                l++;
            else
                r--;
        }
        return ans;
    }
}