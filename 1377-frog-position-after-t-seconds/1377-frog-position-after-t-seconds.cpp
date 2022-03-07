class Solution {
public:
    long double prob=0;
    int target;
    vector<vector<int>> adjList;
    vector<bool> visited;
    bool dfs(int node,int depth,long double prob)
    {
        if(depth<0)
            return false;
        visited[node]=true;
        if(node==target)
        {
            if(depth==0||adjList[node].size()==(node!=1))
                this->prob=prob;
            return true;
        }
        for(int &n:adjList[node])
            if(!visited[n]&&dfs(n,depth-1,prob*(long double)1/(adjList[node].size()-(node!=1))))
                return true;
        return false;                
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {
        adjList.resize(n+1);
        visited.resize(n+1,false);
        this->target=target;
        for(vector<int> &v:edges)
            adjList[v[0]].push_back(v[1]),adjList[v[1]].push_back(v[0]);
        dfs(1,t,1);
        return prob;
    }
};