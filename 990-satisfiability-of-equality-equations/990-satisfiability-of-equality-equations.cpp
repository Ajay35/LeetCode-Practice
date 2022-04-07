struct DisjointSet
{
    int *parent, *rnk;
    int n;
    DisjointSet(int n)
    {
        this->n=n;
        parent=new int[n+1];
        for(int i=0; i<=n; i++)
        {
            parent[i]=i;
        }
    }
    int find(int u)
    {
        if(u!=parent[u])
            parent[u]=find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x=find(x);
        y=find(y);
        parent[x]=y;
    }
};
class Solution 
{
public:
    bool equationsPossible(vector<string>& equations) 
    {
        DisjointSet DSU(26);
        for(int i=0; i<equations.size(); i++)
        {
            if(equations[i][1]=='=')
            {
                DSU.merge(equations[i][0]-'a', equations[i][3]-'a');
            }
        }
        for(int i=0; i<equations.size(); i++)
        {
            if(equations[i][1]=='!')
            {
                if(DSU.find(equations[i][0]-'a')==DSU.find(equations[i][3]-'a'))
                    return false;
            }
        }
        return true;
    }
};