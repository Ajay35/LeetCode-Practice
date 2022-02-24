class WordDistance {
public:
    map<string, vector<int>> words;
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); i++)
        {
            words[wordsDict[i]].push_back(i);    
        }
    }
    
    int shortest(string word1, string word2) {
        int ans = 1e9;
        if(word1==word2)
        {
            vector<int>& v = words[word1];
            for(int i = 1; i < v.size(); i++)
            {
                ans = min(ans, v[i] - v[i - 1]);
            }
        }
        else
        {
            vector<int>& v1 = words[word1];
            vector<int>& v2 = words[word2];
            for(int i = 0; i < v1.size(); i++)
            {
                int x = v1[i];
                int mid;
                int lo = 0;
                int hi = v2.size() - 1;
                while (hi - lo > 1) 
                {
                    mid = (lo + hi) / 2;
                    if (v2[mid] < x) 
                    {
                        lo = mid;
                    } 
                    else 
                    {
                        hi = mid;
                    }
                }
                if (x - v2[lo] <= v2[hi] - x) 
                {
                    ans = min(ans, abs(x - v2[lo]));
                }
                else
                {
                    ans = min(ans, abs(x - v2[hi]));
                }
            }
        }
        return ans;

    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */