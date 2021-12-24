class Solution {
public:
    vector<string> printVertically(string s) {
        int n = s.size();
        int max_len = 0;
        vector<string> words;
        string temp;
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ')
            {
                temp += s[i];
            }
            else
            {
                words.push_back(temp);
                temp.clear();
            }
        }
        words.push_back(temp);
        for(int i = 0; i < words.size(); i++)
        {
            max_len = max(max_len, (int) words[i].size());
        }
        vector<string> ans;
        string cur_word;
        for(int i = 1; i <= max_len; i++)
        {
            for(int j = 0; j < words.size(); j++)
            {
                if(i > words[j].size())
                {
                    cur_word += ' ';
                }
                else
                {
                    cur_word += words[j][i - 1];
                }
            }
            while(cur_word.size() > 1 and cur_word.back() == ' ')
            {
                cur_word = cur_word.substr(0, cur_word.size() - 1);
            }
            ans.push_back(cur_word);
            cur_word.clear();
        }
        return ans;
    }
};