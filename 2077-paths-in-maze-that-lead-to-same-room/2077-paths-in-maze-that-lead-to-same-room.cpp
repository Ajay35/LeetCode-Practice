class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        int m = corridors.size();
        vector<vector<int>> mat(n + 1, vector<int>(n + 1));
        for(int i = 0; i < m; i++)
        {
            mat[corridors[i][0]][corridors[i][1]] = 1;
            mat[corridors[i][1]][corridors[i][0]] = 1;
        }
        
        vector<pair<int, int>> pairs;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(mat[i][j])
                {
                    pairs.push_back({i, j});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < pairs.size(); i++)
        {
            int x = pairs[i].first;
            int y = pairs[i].second;
            int mx = max(x, y);
            for(int j = mx + 1; j <= n; j++)
            {
                if(j != x and j!=y and (mat[x][j] and mat[y][j]))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};