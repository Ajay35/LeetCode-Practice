class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        int n = s.size();
        vector<int> dp(n);
        
        for(int i = 0; i < n; i++)
        {
            if(st.empty() or s[i] == '(')
                st.push(i);
            else if(!st.empty() and s[i] == ')' and s[st.top()] == '(') 
            {
                dp[st.top()] += i - st.top() + 1;
                st.pop();   
            }
            else
            {
                while(!st.empty())
                    st.pop();
            }
        }
        int i = 0;
        while(i < n)
        {
            if(dp[i] > 0)
            {
                int ind = i;
                int t = 0;
                
                while(ind < n and dp[ind] > 0)
                {
                    cout<<ind<<" "<<dp[ind]<<" ";
                    t += dp[ind];
                    ind += dp[ind];
                }
                cout<<endl;
                
                ans = max(ans, t);
                i = ind;
            }
            else
            {
                i++;
            }
        }
        
        return ans;
    }
};