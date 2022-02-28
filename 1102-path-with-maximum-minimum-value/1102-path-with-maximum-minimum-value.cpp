class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    using pp = pair<int,pair<int,int>>;
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        priority_queue<pp> pq;
        pq.push({A[0][0],{0,0}});
        vector<vector<int>> dp(m,vector<int>(n,INT_MIN));
        dp[0][0]=A[0][0];
        while(!pq.empty()){
            auto w = pq.top();pq.pop();
            int val = w.first;
            int x = w.second.first;
            int y = w.second.second;
			if(x==m-1 && y==n-1){
                return val;
            }
            for(int i=0;i<4;i++){
                int xx = x+dx[i];
                int yy = y+dy[i];
                if(xx<0||xx>=m||yy<0||yy>=n) continue;
                if(dp[xx][yy]<(min(dp[x][y],A[xx][yy]))){
                    dp[xx][yy] = min(dp[x][y],A[xx][yy]);
                    pq.push({dp[xx][yy],{xx,yy}});
                }
            }
        }
        return dp[m-1][n-1];
    }
};