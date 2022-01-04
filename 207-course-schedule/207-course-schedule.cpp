class Solution {
public:
    bool cycle(int u, vector<bool>& vis, vector<bool>& st, vector<vector<int>>& g)
    {
        if(vis[u] == false)
        {
            vis[u] = true;
            st[u] = true;
            for(int v: g[u])
            {
                if (!vis[v] && cycle(v, vis, st, g))
                    return true;
                else if (st[v])
                    return true;
            }
        }
        st[u] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> g(n);
        for(int i = 0; i < pre.size(); i++)
        {
            g[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<bool> vis(n, false);
        vector<bool> st(n, false);
        for(int i = 0; i < n; i++)
        {
            if(cycle(i, vis, st, g))
                return false;    
        }
        
        return true;
    }
};