class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        
        map<int, int> flavours;
        int unique_flavours = 0;
        int n = candies.size();
        for(int i = 0; i < n; i++)
        {
            flavours[candies[i]]++;
            if(flavours[candies[i]] == 1)
                unique_flavours++;
        }
        if(k == 0)
            return unique_flavours;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            // remove candy until k size window.
            flavours[candies[i]]--;
            // no other candy remains of this flavour so unique flavours decreases.
            if(flavours[candies[i]] == 0)
                unique_flavours--;
            if(i >= k - 1)
            {
                ans = max(unique_flavours, ans);
                // sliding window, remove the first candy that was entered in a k-window.
                flavours[candies[i - k + 1]]++;
                if(flavours[candies[i - k + 1]] == 1)
                    unique_flavours++;
            }
        }
        return ans;
    }
};