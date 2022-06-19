class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> store = new HashMap<>();
        int n = nums.length;
        for(int i = 0; i < n; i++) {
            if(store.get(target - nums[i]) != null) {
                return new int[] {i, store.get(target - nums[i])};
            }
            store.put(nums[i], i);
        }
        
        return null;
    }
}