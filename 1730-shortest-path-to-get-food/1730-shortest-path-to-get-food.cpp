class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};       
        
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid[i][j] == '*') 
                {
                    q.push(make_pair(i, j));
                    break;
                }
            }
        }
        
        int steps = 0;
        while (!q.empty()) 
        {
            steps++;
            
            int size = q.size();
            for (int i = 0; i < size; i++) 
            {
                auto elem = q.front(); 
                q.pop();
               
                for (int i = 0; i < dirs.size(); i++) 
                {
                    int x = elem.first  + dirs[i][0];
                    int y = elem.second + dirs[i][1];
                
                    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 'X')
                        continue;
                
                    if (grid[x][y] == '#')
                        return steps;
                    
                    grid[x][y] = 'X';
                    q.push(make_pair(x, y));
                }
            }
        }
        return -1;
    }
};