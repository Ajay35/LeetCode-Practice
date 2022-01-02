class Solution {
public:
    void dfs(int u, vector<vector<int>>& g, vector<bool>& vis)
    {
        vis[u] = true;
        for(int v: g[u])
        {
            if(!vis[v])
                dfs(v, g, vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n - 1)
            return -1;
        vector<vector<int>> g(n);
        for(int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<bool> vis(n, false);
        int components = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(i, g, vis);
                components++;
            }
        }
        return components - 1;
    }
};