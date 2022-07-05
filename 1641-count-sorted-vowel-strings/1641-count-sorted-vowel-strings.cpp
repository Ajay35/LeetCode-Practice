class Solution {
public:
    string vowels= "aeiou";
    int f(int n, int ind) {
        if(n == 0) {
            return 1;
        }
        int ans = 0;
        for(int i = ind; i < vowels.size(); i++) {
            ans += f(n - 1, i);
        }
        return ans;
    }
    int countVowelStrings(int n) {
        int ans = f(n, 0);
        return ans;
    }
};