class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
          for (auto i = S.rbegin(); i < S.rend(); i++)
          {
            if (*i != '-') 
            {
              if (res.size()%(K+1) == K) 
                  res += '-';
              res += toupper(*i);
            }
          }

          reverse(res.begin(), res.end());
          return res;
    }
};