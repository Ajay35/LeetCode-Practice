class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> id;
        for (int i = 0; i < req_skills.size(); i++) 
        {
            id[req_skills[i]] = i;
        }
        
        vector<vector<int>> hash(req_skills.size());
        
        for (int i = 0; i < people.size(); i++) 
        {
            for (string &s : people[i]) 
            {
                if (id.find(s) == id.end()) 
                {
                    continue;
                }
                int index = id[s];
                hash[index].push_back(i);
            }
        }
        
        unordered_set<int> path;
		
        unordered_set<int> ans;
        for (int i = 0; i < people.size(); i++) 
        {
            ans.insert(i);
        }
        
        dfs(hash, 0, path, ans);
        
        return vector<int>(ans.begin(), ans.end());
    }
private:
    void dfs(vector<vector<int>> &hash, int index, unordered_set<int> &path, unordered_set<int> &ans) {
        // find a solution, compare with current optimal
        if (index == hash.size()) 
        {
            if (path.size() < ans.size()) 
            {
                ans = path;
            }
            return;
        }
        
        if (path.size() >= ans.size()) 
        {
            return;
        }
        
        for (int &i : hash[index]) 
        {
            bool exist = (path.find(i) != path.end());
            path.insert(i);
            dfs(hash, index + 1, path, ans);
            if (!exist) 
            {
                path.erase(i);
            }
        }
    }
};