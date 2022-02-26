class Solution {
public:

    void dfs(int u, vector<vector<int>>& g, vector<bool>& vis, int& c)
    {
        vis[u] = true;
        c++;
        for(int v: g[u])
        {
            if(!vis[v])
            {
                dfs(v, g, vis, c);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        vector<vector<int>> g(n);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1])
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        int ans = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                int d = 0;
                dfs(i, g, vis, d);
                ans++;
            }
        }
        return stones.size() - ans;
    }
};