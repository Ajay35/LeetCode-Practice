class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto& h : highways) 
        {
            graph[h[0]].push_back({h[1], h[2]});
            graph[h[1]].push_back({h[0], h[2]});
        }
        vector<vector<int>> dp(discounts + 1, vector<int>(n, 1e9));
        for(int i = 0; i < discounts + 1; ++i) 
            dp[i][0] = 0;
        queue<int> cur; 
        cur.push(0);
        while(!cur.empty()) 
        {
            int s = cur.size();
            while(s-- > 0) 
            {
                int from = cur.front();
                cur.pop();
                for(auto &p:graph[from]) 
                {
                    int next = p.first, price = p.second;
                    bool to_add = false;
                    if(dp[0][next] > dp[0][from] + price) 
                    {
                        to_add = true;
                        dp[0][next] = dp[0][from] + price;
                    }
                    for(int d = 1; d <= discounts; ++d) 
                    {
                        int best = min(dp[d][from] + price, dp[d-1][from] + price/2);
                        if(dp[d][next] > best) 
                        {
                            dp[d][next] = best;
                            to_add = true;
                        }
                    }
                    if(to_add) cur.push(next);
                }
            }
        }
        return dp[discounts][n-1]==1e9?-1:dp[discounts][n-1];
    }
};