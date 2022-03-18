class Solution {
public:
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& vis, vector<pair<int, int>>& s)
    {
        vis[x][y] = true;
        s.push_back({x, y});
        
        for(int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];
            
            if(cx>=0 and cx < grid.size() and cy >=0 and cy < grid[0].size() and !vis[cx][cy] and grid[cx][cy]) {
                dfs(grid, cx,cy,vis, s);
            }
        }
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<pair<int, int>>> groups(2);
        int g = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] and grid[i][j])
                {
                    vector<pair<int, int>> spots;
                    
                    dfs(grid, i, j, vis, spots);
                    if(spots.size())
                    {
                        groups[g++] = spots;
                    }
                }
            }
        }
        int ans = n * m;
        for(int i = 0; i < groups[0].size(); i++)   
        {
            for(int j = 0; j < groups[1].size(); j++)
            {
                ans = min(ans , abs(groups[0][i].first-groups[1][j].first) + abs(groups[0][i].second-groups[1][j].second) - 1);
            }
        }
        return ans;
    }
};