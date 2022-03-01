class Solution {
public:
    bool palindrome(string& s)
    {
        int l = 0, r = s.size()-1;
        while(l < r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void f(int i, int j, string& s, vector<string>& cur, vector<vector<string>>& ans)
    {
        if(j == s.size() - 1)
        {
            string temp = s.substr(i, j - i + 1);
            if(palindrome(temp)){
                cur.push_back(temp);
                ans.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        string temp = s.substr(i, j - i + 1);
        if(palindrome(temp))
        {    
            cur.push_back(temp);
            f(j + 1, j + 1, s, cur, ans);
            cur.pop_back();
            f(i, j + 1, s, cur, ans);
        }
        else
        {
            f(i, j + 1, s, cur, ans);
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        
        vector<vector<string>> ans;
        vector<string> cur;
        f(0, 0, s, cur, ans);
        return ans;
    }
};