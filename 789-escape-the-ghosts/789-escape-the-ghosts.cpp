class Solution {
public:
    
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        
        int d = abs(0 - target[0]) + abs(0 - target[1]);
        for(int i = 0; i < ghosts.size(); i++)
        {
            int x = ghosts[i][0];
            int y = ghosts[i][1];
            int md = abs(target[0] - x) + abs(target[1] - y);
            if(md <= d)
                return false;
        }
        
        return true;
        
    }
};