class Solution {
public:
    int totalFruit(vector<int>& fruit) {
        // longest subarray having at most 2 distinct numbers.
        int n = fruit.size();
        vector<int> hash(n);
        int l = 0, d = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            hash[fruit[i]]++;
            if(hash[fruit[i]] == 1)
                d++;
            while(d > 2)
            {
                if(hash[fruit[l]] == 1)
                    d--;
                hash[fruit[l]]--;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};