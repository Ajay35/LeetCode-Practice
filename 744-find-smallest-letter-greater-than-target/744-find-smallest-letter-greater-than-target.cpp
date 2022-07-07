class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size();
        int n = letters.size();
        while(l < r) {
            int mid = (l + r) / 2;
            
            if(letters[mid] <= target) {
                l = mid + 1;
            }
            else if(letters[mid] > target) {
                r = mid;
            }
        }
        
        if(l == n) {
            return letters[0];
        }
        
        return letters[l];
    }
};