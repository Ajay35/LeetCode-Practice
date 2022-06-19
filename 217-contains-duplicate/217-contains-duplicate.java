class Solution {
    public boolean containsDuplicate(int[] nums) {
        int n = nums.length;
        Set<Integer> store = new HashSet<>();
        
        for(int i = 0; i < nums.length; i++)
        {
            if(store.contains(nums[i])) {
                return true;
            }
            store.add(nums[i]);
        }
        
        return false;
    }
}