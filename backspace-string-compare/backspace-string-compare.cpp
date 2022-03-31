class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ind1 = 0, ind2 = 0;
        vector<char> w1(s.size()), w2(t.size());
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] !='#'){
                w1[ind1++] = s[i];
            }
            else{
                ind1--;
                if(ind1 < 0)
                    ind1 = 0;
            }
        }
        w1.resize(ind1);
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] !='#'){
                w2[ind2++] = t[i];
            }
            else{
                ind2--;
                if(ind2 < 0)
                    ind2= 0;
            }
        }
        w2.resize(ind2);
        return w1 == w2; 
    }
};