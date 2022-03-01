class Solution {
public:
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    
    bool dfs(vector<vector<char>>& grid, int i, int j, int pi, int pj, vector<vector<bool>>& vis, int n, int m) {
            vis[i][j] = true;

            for(int k = 0; k < 4; k++) {
                
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if(isValid(ni, nj, n, m) and !(ni == pi and nj == pj) and grid[i][j] == grid[ni][nj]) {
                    
                    if(vis[ni][nj]) {
                        return true;
                    }
                    
                    else if(dfs(grid, ni, nj, i, j, vis, n, m)) {
                        return true;
                    }
                }
            }
            return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j]) {
                    if(dfs(grid, i, j, -1, -1, vis, n, m)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};