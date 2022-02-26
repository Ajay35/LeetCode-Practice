class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    void dfs(vector<vector<char>>& board, int x, int y, int n, int m, vector<vector<bool>>& vis)
    {
        vis[x][y] = true;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 and nx < n and ny >=0 and ny < m and board[nx][ny] == 'O' and !vis[nx][ny])
            {
                dfs(board, nx, ny, m, m, vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((i == 0 or i == n - 1 or j == 0 or j == m - 1) and board[i][j] == 'O' and !vis[i][j])
                {
                    dfs(board, i, j, n, m, vis);
                }
            }
        }
        for(int i = 1; i < n - 1; i++)
        {
            for(int j = 1; j < m - 1; j++)
            {
                if(!vis[i][j] and board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};