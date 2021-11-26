class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        if(n == k)
            return;
        k = k % n;
        int[] left = new int[k];
        int[] right = new int[n - k];
        int le_start = n - k;
        for(int i = 0; i < k; i++)
        {
            left[i] = nums[le_start++]; 
        }
        
        for(int i = 0; i < n - k; i++)
        {
            right[i] = nums[i];
        }
        
        for(int i = 0; i < k; i++)
        {
            nums[i] = left[i];
        }
        for(int i = k; i < n; i++)
        {
            nums[i] = right[i - k];
        }
    }
}