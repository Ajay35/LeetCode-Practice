class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<List<Integer>, List<String>> groups = new HashMap<>();
        
        for(int i = 0; i < strs.length; i++) {
            List<Integer> hash = Arrays.asList(new Integer[26]);
            for(int j = 0; j < strs[i].length(); j++) {
                int index = strs[i].charAt(j) - 'a';
                Integer c = hash.get(index);
                if(c == null) {
                    c = 0;
                }
                hash.set(index, c + 1);
            }
            
            if(groups.get(hash) == null) {
                groups.put(hash, new ArrayList<>());
            }
            
            groups.get(hash).add(strs[i]);
        }
        
        List<List<String>> ans = new ArrayList<List<String>>();
        for(Map.Entry<List<Integer>,List<String>> entry : groups.entrySet()) {
            ans.add(entry.getValue());
        }
        
        return ans;
    }
}