class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> que;
        int n = rooms.size();
        int m = rooms[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(rooms[i][j] == 0)
                {
                    que.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        
        while(!que.empty())
        {
            pair<int, int> cur=que.front();
            que.pop();
            for(int i = 0; i < 4; i++)
            {
                int ni = cur.first + dx[i];
                int nj = cur.second + dy[i];
                if(ni >=0 and ni < n and nj >=0 and nj < m and !vis[ni][nj] and rooms[cur.first][cur.second] + 1 < rooms[ni][nj])
                {
                    que.push({ni, nj});
                    vis[ni][nj] = true;
                    rooms[ni][nj] = 1 + rooms[cur.first][cur.second];
                }
            }
            
        }
    }
};