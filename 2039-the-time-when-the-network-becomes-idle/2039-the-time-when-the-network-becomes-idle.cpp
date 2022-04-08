class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) 
    {
        auto n = patience.size();
        vector<int> dist(n, INT_MAX);
        vector<vector<int>> graph(n);
        for (auto &edge:edges) 
        {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> queue;
        vector<bool> visited(n, false);
        queue.push(0);
        visited[0] = true;
        int d = 0;
        while (!queue.empty()) 
        {
            for (auto i = queue.size(); i > 0; i--) 
            {
                int u = queue.front();
                queue.pop();
                dist[u] = d;
                for (auto v:graph[u]) 
                {
                    if (!visited[v]) 
                    {
                        queue.push(v);
                        visited[v] = true;
                    }
                }
            }
            d++;
        }

        int slowest = 0;
        for (int i = 1; i < n; i++) 
        {
            int firstTimeReceive = dist[i] * 2; 
            int waitingTime = firstTimeReceive - 1;
            int numResend = waitingTime / patience[i];
            int timeDone = firstTimeReceive + numResend * patience[i];
            slowest = max(slowest, timeDone);
        }
        return slowest + 1;
    }
};