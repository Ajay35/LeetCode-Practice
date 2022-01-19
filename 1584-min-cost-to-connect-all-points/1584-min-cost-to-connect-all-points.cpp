class Solution {
public:
    vector<int> parent, sz;
    int dis(int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y2 - y1);
    }
    int find_set(int u)
    {
        if(parent[u] == u)
            return u;
        return parent[u] = find_set(parent[u]);
    }
    
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a != b)
        {
            if(sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>> edges;
        int n = points.size();
        parent.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                edges.push_back({dis(x1, y1, x2, y2),{i + 1, j + 1}});
            }
        }
        sort(begin(edges), end(edges), [&](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
             {
                 return a.first < b.first;
             });
        int cnt = 0, ans = 0;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int w = edges[i].first;
            if(find_set(u) != find_set(v))
            {
                ans += w;
                cnt++;
                union_sets(u, v);
                if(cnt == n - 1)
                    break;
            }
        }
        return ans;
    }
};