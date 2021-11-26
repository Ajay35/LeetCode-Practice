class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int l = 0, r = n - 1;
        int[] ans = new int[n];
        int ind = 0;
        while(l <= r) {
            int le = nums[l] * nums[l];
            int ri = nums[r] * nums[r];
            
            if(le <= ri) {
                ans[ind++] = le;
                l++;
            }
            else {
                ans[ind++] = ri;
                r--;
            }
        }
        Arrays.sort(ans);
        return ans;
    }
}