class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        if(num.size() == k)
        {
            return "0";
        }
        string ans;
        for(int i = 0; i < num.size() and k > 0; i++)
        {
            if(st.empty())
            {
               st.push(i); 
            }
            else if(num[st.top()] > num[i])
            {
                while(!st.empty() and num[st.top()] > num[i] and k > 0)
                {
                    num[st.top()] = '-';
                    st.pop();
                    k--;
                }
                st.push(i);
            }
            else
            {
                st.push(i);
            }
        }
        while(k > 0 and !st.empty())
        {
            num[st.top()] = '-';
            st.pop();
            k--;
        }
        
        for(int i = 0; i < num.size(); i++)
        {
            if(num[i] != '-')
                ans += num[i];
        }
        
        int ind = 0;
        while(ind + 1 < ans.size() and ans[ind] == '0')
        {
            ind++;
        }
        ans = ans.substr(ind);
        return ans;
    }
};