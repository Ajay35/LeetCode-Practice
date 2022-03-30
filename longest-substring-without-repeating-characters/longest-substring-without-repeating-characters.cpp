class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> a(256);
        int d = 0;
        int n = s.size();
        int l = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            a[s[i]]++;
            while(a[s[i]] > 1)
            {
                a[s[l]]--;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};