class Solution {
    public boolean containsDuplicate(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> store = new HashMap<>();
        
        for(int i = 0; i < nums.length; i++)
        {
            Integer c = store.get(nums[i]);
            
            if(c != null && c == 1) {
                return true;
            }
            else {
                c = 0;
                store.put(nums[i], c + 1);
            }
        }
        
        return false;
    }
}