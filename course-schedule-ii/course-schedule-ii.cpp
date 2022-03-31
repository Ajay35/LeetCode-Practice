class Solution {
public:
    vector<vector<int>> g;
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> in(n);
        g.resize(n);
        for(int i = 0; i < pre.size(); i++)
        {
            g[pre[i][1]].push_back(pre[i][0]);
            in[pre[i][0]]++;
        }
        queue<int> que;
        for(int i = 0; i < n; i++)
        {
            if(in[i] == 0)
                que.push(i);
        }
        vector<int> ans(n);
        int ind = 0;
        
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            for(int v: g[cur])
            {
                if(--in[v] == 0)
                    que.push(v);
            }
            ans[ind++] = cur;
        }
        if(ind == n)
            return ans;
        return {};
    }
};