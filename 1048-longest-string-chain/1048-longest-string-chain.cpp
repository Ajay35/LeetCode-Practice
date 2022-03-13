class Solution {
public:
    vector<vector<string>> store;
    
    bool ok(string& s, string& t)
    {
        int sz1 = s.size();
        int sz2 = t.size();
        if(sz1+1 != sz2)
            return false;
        int l1 = 0, l2 = 0, cnt = 0;
        while(l1 < sz1 and l2 < sz2)
        {
            if(s[l1] != t[l2])
            {
                if(cnt == 1)
                    return false;
                l2++;
                cnt++;
            }
            else
            {
                l1++;
                l2++;
            }
        }
        if(l2 < t.size())
            return true;
        return cnt == 1;
    }
    map<string, int> memo;
    int dfs(string w, int ind)
    {
        int ret = 0;
        if(ind > 16)
            return 0;
        if(memo.find(w) != memo.end())
            return memo[w];
        for(int i = 0; i < store[ind].size(); i++)
        {
            if(ok(w, store[ind][i]))
            {
                ret = max(ret, 1 + dfs(store[ind][i], ind + 1));
            }
        }
        return memo[w] = ret;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        store.resize(17);
        
        for(int i = 0; i < n; i++)
        {
            int len = words[i].size();
            store[len].push_back(words[i]);    
        }
        int ans = 1;
        for(int i = 1; i <= 16 ; i++)
        {
            for(int j = 0; j < store[i].size(); j++)
            {
                string w = store[i][j];
                int len = 1 + dfs(w, i + 1);
                ans = max(ans, len);
            }
        }
        return ans;
    }
};