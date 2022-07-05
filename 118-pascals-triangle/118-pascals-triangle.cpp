class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> triangle(n);
        
        triangle[0].push_back(1);
        
        if(n == 1) {
            return triangle;
        }
        
        triangle[1].push_back(1);
        triangle[1].push_back(1);
       
            
        for(int i = 2; i < n; i++) {
            triangle[i].push_back(1);
            for(int j = 1; j < i; j++) {
                triangle[i].push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
            }
            triangle[i].push_back(1);
        }
        
        return triangle;
    }
};