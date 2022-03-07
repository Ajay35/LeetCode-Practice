class Solution {
public:
    bool present_on_right(string& s, char ch, int ind)
    {
        for(int i = ind + 1; i < s.size(); i++)
        {
            if(s[i] == ch)
                return true;
        }
        return false;
    }
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<bool> present(26, false);
        for(int i = 0; i < s.size(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                present[s[i] - 'a'] = true;
            }
            while(!st.empty() and !present[s[i]-'a'] and st.top() > s[i] and present_on_right(s, st.top(), i))
            {
                present[st.top() - 'a'] = false;
                st.pop();
            }
            if(!present[s[i]-'a'])
            {
                present[s[i]-'a']=true;
                st.push(s[i]);
            }
            
        }
        string ans;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};