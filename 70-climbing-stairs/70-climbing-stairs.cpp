class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        
        if(n <= 1) {
            return n;
        }
        
        int a = 1, b = 1;
        
        for(int i = 2; i <= n; i++) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        
        return b;
    }
};