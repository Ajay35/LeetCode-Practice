class Solution {
public:
    
    long long maxAlternatingSum(vector<int>& A) {
        long long odd = 0, even = 0;
        for (int& a: A)
            even = max(even, odd + a),
            odd = even - a;
        return even;   
    }
};