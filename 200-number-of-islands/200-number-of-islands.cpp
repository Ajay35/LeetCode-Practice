class Solution {
public:
    int dx[4] = {1, 0,-1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<char>>& grid, int x, int y, int n, int m)
    {
        grid[x][y] = '0';
        for(int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx >= 0 and newx < n and newy >= 0 and newy < m and grid[newx][newy] =='1')
                dfs(grid, newx, newy, n, m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};