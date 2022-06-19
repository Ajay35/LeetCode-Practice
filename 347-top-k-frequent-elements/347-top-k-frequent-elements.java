class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> frequency = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            frequency.put(nums[i], frequency.getOrDefault(nums[i], 0) + 1);
        }
        
        List<Pair<Integer, Integer>> allPairs = new ArrayList<>();
        
        for(Map.Entry<Integer,Integer> entry: frequency.entrySet()) {
            Integer key = entry.getKey();
            Integer val = entry.getValue();
            allPairs.add(new Pair<Integer, Integer>(key, val));
        }
        
        Collections.sort(allPairs, new Comparator<Pair<Integer, Integer>>() {
            @Override
            public int compare(final Pair<Integer, Integer> o1, final Pair<Integer, Integer> o2) {
                return o2.getValue() - o1.getValue();
            }
        });
            
        int[] ans = new int[k];
            
        for(int i = 0; i < k; i++) {
            ans[i] = allPairs.get(i).getKey();
        }
            
        return ans;
        
    }
}