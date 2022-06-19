class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> conversions = new HashMap<>();
        conversions.put('I', 1);
        conversions.put('V', 5);
        conversions.put('X', 10);
        conversions.put('L', 50);
        conversions.put('C', 100);
        conversions.put('D', 500);
        conversions.put('M', 1000);
        
        int ans = 0;
        int n = s.length();
            
        for(int i = 0; i < s.length(); i++) {
            char ch1 = s.charAt(i);
            if(ch1 == 'I') {
                if(i + 1 < n && ((s.charAt(i + 1) == 'V') || (s.charAt(i + 1) == 'X'))) {
                    ans+= (conversions.get(s.charAt(i + 1)) - 1);
                    i++;
                }
                else {
                    ans += conversions.get(ch1);
                }
            }
            else if(ch1 == 'X') {
                if(i + 1 < n && ((s.charAt(i + 1) == 'L') || (s.charAt(i + 1) == 'C'))) {
                    ans+= (conversions.get(s.charAt(i + 1)) - 10);
                    i++;
                }
                else {
                    ans += conversions.get(ch1);
                }
            }
            
            else if(ch1 == 'C') {
                if(i + 1 < n && ((s.charAt(i + 1) == 'D') || (s.charAt(i + 1) == 'M'))) {
                    ans+= (conversions.get(s.charAt(i + 1)) - 100);
                    i++;
                }
                else {
                    ans += conversions.get(ch1);
                }
            }
            else {
                ans += conversions.get(ch1);
            }
        }
        
        return ans;
    }
}