class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 0)
            return false;
   
        int smallest = matrix[0][0], largest = matrix[n - 1][m - 1];
        if (target < smallest || target > largest)
            return false;

        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            if (matrix[i][j] > target)
                j--;
            else
                i++;
        }

        return false;
    }
};